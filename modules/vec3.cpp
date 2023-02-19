
export module vec3;

enum {_XC, _YC, _ZC, _WC};

class vec3 {
    public:
        float data[3];

        vec3() {
            data[0] = 0.0;
            data[1] = 0.0;
            data[2] = 0.0;
        }

        vec3(float x, float y, float z) {
            data[0] = x;
            data[1] = y;
            data[2] = z;
        }

        ~vec3() {}

        float operator[](const int id) const {
			return data[id];
		};

		float &operator[](const int id) {
			return data[id];
		};

		vec3 &operator=(const vec3 &v) {
			data[_XC] = v[_XC];
			data[_YC] = v[_YC];
			data[_ZC] = v[_ZC];

			return (*this);
		};
};

vec3 vec3Cross(vec3 a, vec3 b) {
    vec3 rt;

	rt[0] = a[_YC]*b[_ZC] - a[_ZC]*b[_YC];
	rt[1] = a[_ZC]*b[_XC] - a[_XC]*b[_ZC];
	rt[2] = a[_XC]*b[_YC] - a[_YC]*b[_XC];

	return rt;
}