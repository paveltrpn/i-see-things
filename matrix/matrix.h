
#include <concepts>
#include <iostream>

#include <type_traits>

template <typename T>
requires std::floating_point<T>
class matrix_c {
    public:
        matrix_c(size_t rws, size_t clms) : rows_(rws), columnes_(clms) {
            allocate();
        };

        matrix_c(const matrix_c &rhs) : rows_(rhs.rows_), columnes_(rhs.columnes_) {
            data_ = new T *[rows_];
            for (size_t i = 0; i < rows_; ++i) {
                data_[i] = new T[columnes_];
                std::copy(rhs.data_[i], rhs.data_[i] + columnes_, data_[i]);
            }
        };

        matrix_c(matrix_c &&rhs) : rows_(0), columnes_(0), data_(nullptr) {
            rows_ = rhs.rows_;
            columnes_ = rhs.columnes_;
            // stole just "primary" pointer!
            data_ = rhs.data_;
            // is it enought to nullptr a rows pointer and not set
            // to null every column pointer? I.e. if object lost
            // "primary" pointer then every other underlying pointer
            // is also will be unavaible.
            rhs.data_ = nullptr;
            rhs.rows_ = rhs.columnes_ = 0;
        };

        matrix_c &operator=(const matrix_c &rhs) {
            if (this != &rhs) {
                deallocate();

                rows_ = rhs.rows_;
                columnes_ = rhs.columnes_;

                data_ = new T *[rows_];
                for (size_t i = 0; i < rows_; ++i) {
                    data_[i] = new T[columnes_];
                    std::copy(rhs.data_[i], rhs.data_[i] + columnes_, data_[i]);
                }
            }
            return *this;
        };

        matrix_c &&operator=(matrix_c &&rhs) {
            if (this != &rhs) {
                deallocate();

                rows_ = rhs.rows_;
                columnes_ = rhs.columnes_;

                data_ = rhs.data_;

                rhs.data_ = nullptr;
                rhs.rows_ = rhs.columnes_ = 0;
            }

            return std::move(rhs);
        };

        ~matrix_c() {
            deallocate();
        };

        matrix_c &operator*(const matrix_c &rhs) {
            for (auto i = 0; i < rows_; ++i) {
                for (auto j = 0; j < rhs.columnes_; ++j) {
                }
            }
        };

        void mult(const matrix_c &rhs) {
            if (rows_ != rhs.columnes_) {
                return;
            }

            for (auto i = 0; i < rows_; ++i) {
                for (auto j = 0; j < rhs.columnes_; ++j) {
                }
            }
        }

        void transpose() {
        }

        void invert() {
        }

        void getDeterminant() {
        }

        size_t getRowsNumber() const {
            return rows_;
        }

        size_t getColumnesNumber() const {
            return columnes_;
        }

        void setIdtt() {
            // for non square matrix skip this function
            if (rows_ != columnes_) {
                return;
            }

            for (size_t i = 0; i < rows_; ++i) {
                for (size_t j = 0; j < columnes_; ++j) {
                    if (i == j) {
                        data_[i][j] = 1.0;
                    }
                }
            }
        }

        void print() {
            for (size_t i = 0; i < rows_; ++i) {
                for (size_t j = 0; j < columnes_; ++j) {
                    std::cout << data_[i][j];
                }
                std::cout << "\n";
            }
        }

    private:
        size_t rows_, columnes_;
        T **data_;

        void allocate() {
            data_ = new T *[rows_];
            for (size_t i = 0; i < rows_; ++i) {
                data_[i] = new T[columnes_];
            }
        }

        void deallocate() {
            // Checking pointer to null before deleting is not necessary
            // but in this case i don't sure is it safe to itarate across
            // potentially not nullptr pointer and delete it's sub arrays.
            if (data_ != nullptr) {
                for (size_t i = 0; i < rows_; ++i) {
                    delete[] data_[i];
                }
                delete[] data_;
            }
        }
};
