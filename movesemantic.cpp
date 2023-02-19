
#include <iostream>
#include <memory>
#include <malloc.h>
#include <cstring>

//   Класс с тремя конструкторами -
//   по умолчанию, перемещения и копирования и 
//   операторами копирования и перемещения.
//   Заодно здесь памятка про выделение памяти в С++,
//   в С есть malloc() и free(), тут мы имеем
//   new и delete (и delete[]) */

//   bool is_one_of - переменная, принимающая результат
//   шаблонного выражения (std::is_same_v<T, Args> || ...), использующего variadic template,
//   в котором проверяется соответствие типа Т списку типов Args. */
template<class T, class ... Args>
constexpr bool is_one_of = (std::is_same_v<T, Args> || ...);

//   Стандарт C++ говорит следующее [п.14.1.2]:
//   "There is no semantic difference between class and typename in a template-parameter." */
template <typename T>
class move_sem_c {
    private:
        size_t allocated;
        std::unique_ptr<T[]> heap;

        //    static_assert() проверяет соответствие типа Т списку типов.
        //    может находится в любом месте кода  В отличие от assert, который выполняется во 
        //    время выполнения, static_assert выполняется во время компиляции, вызывая ошибку 
        //    компилятора, если условие не является истинным. Если условие ложное, то выводится 
        //    диагностическое сообщение. Поскольку static_assert не обрабатывается во время выполнения, 
        //    то стейтменты static_assert могут быть размещены в любом месте кода (даже в глобальном пространстве).
        //
        //    move_sem_c<T> bar - примет только int и Float
        static_assert(is_one_of<T, int, float>, "static_assert(): move_sem_c: T *heap - bad type!");

    public:
        // конструктор по умолчанию
        move_sem_c(): allocated(0), heap(nullptr) {};

        // основной конструктор
        move_sem_c(size_t size): allocated(size) {
            //   Нужно ли делать свой Deleter для unique_ptr,
            //   содержащий массив чисел типа T?????????????
            heap = std::make_unique<T[]>(allocated*sizeof(T));
        }

        //   конструктор копирования.
        //   если он приватный, то это запрещает копирование экземпляров класса
        move_sem_c(const move_sem_c &other) {
            //   на случай попытки копирования неинициализорованного класса
            if (other.allocated == 0) {
                allocated = 0;
                heap = nullptr;
                return;
            }

            allocated = other.allocated;
            heap = std::make_unique<T[]>(allocated*sizeof(T));
            std::memcpy(reinterpret_cast<char*>(heap.get()), 
                        reinterpret_cast<char*>(other.heap.get()), 
                        allocated*sizeof(T));
        };

        //   конструктор перемещения
        //   при перемещении старый объект обнуляется
        //   std::move() перемещает bar в новый unique_ptr
        move_sem_c(move_sem_c &&other) {
            allocated = other.allocated;
            other.allocated = 0;

            heap = std::move(other.heap);
        };

        ~move_sem_c() {
            allocated = 0;
            heap.reset();
        };

        //   Оператор присваивания копированием
        //   Порождённый объект будет "таким же, но не им", т.е. иметь теже данные, но в другой области памяти.
        move_sem_c& operator=(const move_sem_c &other) {
            if (other.allocated == 0) {
                allocated = 0;
                heap = nullptr;
                return *this;
            }

            allocated = other.allocated;
            heap = std::make_unique<T[]>(allocated*sizeof(T));
            std::memcpy(reinterpret_cast<char*>(heap.get()), 
                        reinterpret_cast<char*>(other.heap.get()), 
                        allocated*sizeof(T));

            // Возвращаем текущий объект, чтобы иметь возможность связать в цепочку выполнение нескольких операций присваивания
            return *this;
        };

        // Оператор перемещения
        // 
        move_sem_c& operator=(move_sem_c&& other) {
            allocated = other.allocated;
            other.allocated = 0;

            heap = std::move(other.heap);

            // Возвращаем текущий объект, чтобы иметь возможность связать в цепочку выполнение нескольких операций присваивания
            return *this;
        };

        void free() {
            allocated = 0;
            //   у unique_ptr память освобождает именно reset() (см. справочник для использования)
            //   release() просто освобождает владение ресурсом и unique_ptr становится свободным
            //   но занятая память не освобождается. 
            heap.reset();
        };

        //   malloc_usable_size(void *foo)  -  obtain  size of block of memory allocated from
        //   heap. The main use of this function is for debugging and introspection.
        void show_allocated() {
            std::cout << "move_sem_c(this) - " << this << "\n" <<
                "allocated - " << allocated << "\n" <<
                "malloc_usable_size - " << malloc_usable_size(heap.get())/sizeof(T) << " bytes\n" << 
                "heap place - " << heap.get() << "\n" << std::endl;
        };
};

template <typename T>
class first_foo_c {
    private:
        T bar;
        //   проверка на соответствие Т типу int. Работает только с одним аргументом
        //   в отличии от варианта выше на основе variadic template. В общем относительно
        //   бесполезно 
        static_assert(std::is_same_v<T, int>, "static_assert(): first_foo_c: T bar - bad type!");

    public:
        first_foo_c() {

        };

        ~first_foo_c() {

        };
};

move_sem_c<int> returner() {
    std::cout << "returner() allocated var bar(200)" << std::endl;

    move_sem_c<int> bar(200);
    bar.show_allocated();

    return bar;
};

int movesemantic_test() {
    std::cout << "TEST - movesemantic.cpp" << "\n" << std::endl;

    std::cout << "Allocated var bar(10)" << std::endl;
    move_sem_c<int> bar(10);
    bar.show_allocated();

    std::cout << "Allocated var bar_second by copy bar" << std::endl;
    move_sem_c<int> bar_second(bar); // нельзя, если конструктор копирования приватный 
    bar_second.show_allocated();

    std::string word;
    std::cin >> word; // ждём .....

    std::cout << "allocate bar_huge(1024*100000) " << std::endl;
    move_sem_c<int> bar_huge(1024*100000);
    bar_huge.show_allocated();

    std::cin >> word; // ждём .....

    std::cout << "free bar_huge(1024*100000) " << std::endl;
    bar_huge.free();
    bar_huge.show_allocated();

    std::cin >> word; // ждём .....
    
    move_sem_c<int> bar_third = returner();
    std::cout << "Allocated var bar_third by moving from function returner()" << std::endl;
    bar_third.show_allocated();

    std::cout << "Allocated var bar_fourth = bar_third" << std::endl;
    move_sem_c<int> bar_fourth = bar_third;
    bar_fourth.show_allocated();
    
    first_foo_c<int> bar2;

    return 0;
}