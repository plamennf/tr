#ifndef MY_MATH_H
#define MY_MATH_H

#include "utils.h"

#include <math.h>

#define PI32 3.14159265359f

inline float
to_radians(float degrees)
{
    float result = degrees * (PI32 / 180.0f);
    return result;
}

inline float
to_degrees(float radians)
{
    float result = radians * (180.0f / PI32);
    return result;
}

struct vec2
{
    union
    {
        struct { float x, y; };
        struct { float r, g; };
        float elements[2];
    };

    inline float &
    operator[](size_t index)
    {
        ASSERT(index >= 0);
        ASSERT(index < 2);
        return elements[index];
    }

    inline float const &
    operator[](size_t index) const
    {
        ASSERT(index >= 0);
        ASSERT(index < 2);
        return elements[index];
    }
};

inline vec2
make_vec2(float x, float y)
{
    vec2 result;

    result.x = x;
    result.y = y;

    return result;
}

inline vec2
make_vec2(float value)
{
    vec2 result;

    result.x = value;
    result.y = value;

    return result;
}

inline vec2
operator-(vec2 a)
{
    vec2 result;

    result.x = -a.x;
    result.y = -a.y;
    
    return result;
}

inline vec2
operator+(vec2 a, vec2 b)
{
    vec2 result;

    result.x = a.x + b.x;
    result.y = a.y + b.y;

    return result;
}

inline vec2
operator-(vec2 a, vec2 b)
{
    vec2 result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;

    return result;
}

inline vec2
operator*(vec2 a, float b)
{
    vec2 result;

    result.x = a.x * b;
    result.y = a.y * b;

    return result;
}

inline vec2
operator*(float a, vec2 b)
{
    vec2 result;

    result.x = a * b.x;
    result.y = a * b.y;

    return result;
}

inline vec2
operator/(vec2 a, vec2 b)
{
    vec2 result;

    result.x = a.x / b.x;
    result.y = a.y / b.y;
    
    return result;
}

inline vec2
operator/(vec2 a, float b)
{
    vec2 result;

    float inv_b = 1.0f / b;

    result.x = a.x * inv_b;
    result.y = a.y * inv_b;
    
    return result;
}

inline vec2 &
operator+(vec2 &a, vec2 b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

inline vec2 &
operator-(vec2 &a, vec2 b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

inline vec2 &
operator*(vec2 &a, float b)
{
    a.x *= b;
    a.y *= b;
    return a;
}

inline vec2 &
operator/(vec2 &a, vec2 b)
{
    a.x /= b.x;
    a.y /= b.y;
    return a;
}

inline vec2 &
operator/(vec2 &a, float b)
{
    float inv_b = 1.0f / b;
    
    a.x *= inv_b;
    a.y *= inv_b;
    return a;
}

inline float
length_squared(vec2 a)
{
    float result = a.x*a.x + a.y*a.y;
    return result;
}

inline float
length(vec2 a)
{
    float len_sq = length_squared(a);
    float result = sqrtf(len_sq);
    return result;
}

inline vec2
normalize_or_zero(vec2 a)
{
    vec2 result = {};
    
    float len_sq = length_squared(a);
    if (len_sq > SQUARE(0.001f))
    {
        float len = sqrtf(len_sq);
        float inv_len = 1.0f / len;

        result.x = a.x * inv_len;
        result.y = a.y * inv_len;
    }

    return result;
}

inline float
dot_product(vec2 a, vec2 b)
{
    float result = a.x*b.x + a.y*b.y;
    return result;
}

inline vec2
componentwise_product(vec2 a, vec2 b)
{
    vec2 result;

    result.x = a.x * b.x;
    result.y = a.y * b.y;

    return result;
}

struct vec3
{
    union
    {
        struct { float x, y, z; };
        struct { float r, g, b; };
        float elements[3];
    };

    inline float &operator[](size_t index)
    {
        ASSERT(index >= 0);
        ASSERT(index < 3);
        return elements[index];
    }

    inline float const &operator[](size_t index) const
    {
        ASSERT(index >= 0);
        ASSERT(index < 3);
        return elements[index];
    }
};

inline vec3
make_vec3(float x, float y, float z)
{
    vec3 result;

    result.x = x;
    result.y = y;
    result.z = z;

    return result;
}

inline vec3
make_vec3(float value)
{
    vec3 result;

    result.x = value;
    result.y = value;
    result.z = value;

    return result;
}

inline vec3
operator-(vec3 a)
{
    vec3 result;

    result.x = -a.x;
    result.y = -a.y;
    result.z = -a.z;
 
    return result;
}

inline vec3
operator+(vec3 a, vec3 b)
{
    vec3 result;

    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;

    return result;
}

inline vec3
operator-(vec3 a, vec3 b)
{
    vec3 result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;

    return result;
}

inline vec3
operator*(vec3 a, float b)
{
    vec3 result;

    result.x = a.x * b;
    result.y = a.y * b;
    result.z = a.z * b;

    return result;
}

inline vec3
operator*(float a, vec3 b)
{
    vec3 result;

    result.x = a * b.x;
    result.y = a * b.y;
    result.z = a * b.z;

    return result;
}

inline vec3
operator/(vec3 a, vec3 b)
{
    vec3 result;

    result.x = a.x / b.x;
    result.y = a.y / b.y;
    result.z = a.z / b.z;
    
    return result;
}

inline vec3
operator/(vec3 a, float b)
{
    vec3 result;

    float inv_b = 1.0f / b;

    result.x = a.x * inv_b;
    result.y = a.y * inv_b;
    result.z = a.z * inv_b;
    
    return result;
}

inline vec3 &
operator+(vec3 &a, vec3 b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    
    return a;
}

inline vec3 &
operator-(vec3 &a, vec3 b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    
    return a;
}

inline vec3 &
operator*(vec3 &a, float b)
{
    a.x *= b;
    a.y *= b;
    a.z *= b;
    
    return a;
}

inline vec3 &
operator/(vec3 &a, vec3 b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    
    return a;
}

inline vec3 &
operator/(vec3 &a, float b)
{
    float inv_b = 1.0f / b;
    
    a.x *= inv_b;
    a.y *= inv_b;
    a.z *= inv_b;
    
    return a;
}

inline float
length_squared(vec3 a)
{
    float result = a.x*a.x + a.y*a.y + a.z*a.z;
    return result;
}

inline float
length(vec3 a)
{
    float len_sq = length_squared(a);
    float result = sqrtf(len_sq);
    return result;
}

inline vec3
normalize_or_zero(vec3 a)
{
    vec3 result = {};
    
    float len_sq = length_squared(a);
    if (len_sq > SQUARE(0.001f))
    {
        float len = sqrtf(len_sq);
        float inv_len = 1.0f / len;

        result.x = a.x * inv_len;
        result.y = a.y * inv_len;
        result.z = a.z * inv_len;
    }

    return result;
}

inline float
dot_product(vec3 a, vec3 b)
{
    float result = a.x*b.x + a.y*b.y + a.z*b.z;
    return result;
}

inline vec3
cross_product(vec3 a, vec3 b)
{
    vec3 result;

    result.x = a.y*b.z - a.z*b.y;
    result.y = a.z*b.x - a.x*b.z;
    result.z = a.x*b.y - a.y*b.x;
}

inline vec3
componentwise_product(vec3 a, vec3 b)
{
    vec3 result;

    result.x = a.x * b.x;
    result.y = a.y * b.y;
    result.z = a.z * b.z;

    return result;
}

struct vec4
{
    union
    {
        struct { float x, y, z, w; };
        struct { float r, g, b, a; };
        float elements[4];
    };

    inline float &operator[](size_t index)
    {
        ASSERT(index >= 0);
        ASSERT(index < 4);
        return elements[index];
    }

    inline float const &operator[](size_t index) const
    {
        ASSERT(index >= 0);
        ASSERT(index < 4);
        return elements[index];
    }
};

inline vec4
make_vec4(float x, float y, float z, float w)
{
    vec4 result;

    result.x = x;
    result.y = y;
    result.z = z;
    result.w = w;

    return result;
}

inline vec4
make_vec4(float value)
{
    vec4 result;

    result.x = value;
    result.y = value;
    result.z = value;
    result.w = value;

    return result;
}

inline vec4
operator-(vec4 a)
{
    vec4 result;

    result.x = -a.x;
    result.y = -a.y;
    result.z = -a.z;
    result.w = -a.w;

    return result;
}

inline vec4
operator+(vec4 a, vec4 b)
{
    vec4 result;

    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    result.w = a.w + b.w;

    return result;
}

inline vec4
operator-(vec4 a, vec4 b)
{
    vec4 result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    result.w = a.w - b.w;

    return result;
}

inline vec4
operator*(vec4 a, float b)
{
    vec4 result;

    result.x = a.x * b;
    result.y = a.y * b;
    result.z = a.z * b;
    result.w = a.w * b;

    return result;
}

inline vec4
operator*(float a, vec4 b)
{
    vec4 result;

    result.x = a * b.x;
    result.y = a * b.y;
    result.z = a * b.z;
    result.w = a * b.w;

    return result;
}

inline vec4
operator/(vec4 a, vec4 b)
{
    vec4 result;

    result.x = a.x / b.x;
    result.y = a.y / b.y;
    result.z = a.z / b.z;
    result.w = a.w / b.w;
    
    return result;
}

inline vec4
operator/(vec4 a, float b)
{
    vec4 result;

    float inv_b = 1.0f / b;

    result.x = a.x * inv_b;
    result.y = a.y * inv_b;
    result.z = a.z * inv_b;
    result.w = a.w * inv_b;
    
    return result;
}

inline vec4 &
operator+(vec4 &a, vec4 b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    a.w += b.w;
    
    return a;
}

inline vec4 &
operator-(vec4 &a, vec4 b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    a.w -= b.w;
    
    return a;
}

inline vec4 &
operator*(vec4 &a, float b)
{
    a.x *= b;
    a.y *= b;
    a.z *= b;
    a.w *= b;
    
    return a;
}

inline vec4 &
operator/(vec4 &a, vec4 b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    a.w /= b.w;
    
    return a;
}

inline vec4 &
operator/(vec4 &a, float b)
{
    float inv_b = 1.0f / b;
    
    a.x *= inv_b;
    a.y *= inv_b;
    a.z *= inv_b;
    a.w *= inv_b;
    
    return a;
}

inline float
length_squared(vec4 a)
{
    float result = a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w;
    return result;
}

inline float
length(vec4 a)
{
    float len_sq = length_squared(a);
    float result = sqrtf(len_sq);
    return result;
}

inline vec4
normalize_or_zero(vec4 a)
{
    vec4 result = {};
    
    float len_sq = length_squared(a);
    if (len_sq > SQUARE(0.001f))
    {
        float len = sqrtf(len_sq);
        float inv_len = 1.0f / len;

        result.x = a.x * inv_len;
        result.y = a.y * inv_len;
        result.z = a.z * inv_len;
        result.w = a.w * inv_len;
    }

    return result;
}

inline float
dot_product(vec4 a, vec4 b)
{
    float result = a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
    return result;
}

inline vec4
componentwise_product(vec4 a, vec4 b)
{
    vec4 result;

    result.x = a.x * b.x;
    result.y = a.y * b.y;
    result.z = a.z * b.z;
    result.w = a.w * b.w;
    
    return result;
}

// mat4 is row-major which means elements[row][column]
struct mat4
{
    union
    {
        struct
        {
            float _11, _12, _13, _14;
            float _21, _22, _23, _24;
            float _31, _32, _33, _34;
            float _41, _42, _43, _44;
        };
        vec4 rows[4];
        float elements[4][4];
    };

    inline vec4 &
    operator[](size_t index)
    {
        ASSERT(index >= 0);
        ASSERT(index < 4);
        return rows[index];
    }

    inline vec4 const &
    operator[](size_t index) const
    {
        ASSERT(index >= 0);
        ASSERT(index < 4);
        return rows[index];
    }
};

inline mat4
mat4_identity(void)
{
    mat4 result = {};

    result._11 = 1.0f;
    result._22 = 1.0f;
    result._33 = 1.0f;
    result._44 = 1.0f;

    return result;
}

inline mat4
operator+(mat4 a, mat4 b)
{
    mat4 result;

    for (int row = 0; row < 4; ++row)
    {
        for (int col = 0; col < 4; ++col)
        {
            result.elements[row][col] = a.elements[row][col] + b.elements[row][col];
        }
    }
    
    return result;
}

inline mat4
operator-(mat4 a, mat4 b)
{
    mat4 result;

    for (int row = 0; row < 4; ++row)
    {
        for (int col = 0; col < 4; ++col)
        {
            result.elements[row][col] = a.elements[row][col] - b.elements[row][col];
        }
    }
    
    return result;
}

inline mat4
operator*(mat4 a, mat4 b)
{
    mat4 result;

    for (int row = 0; row < 4; ++row)
    {
        for (int col = 0; col < 4; ++col)
        {
            float accum = 0.0f;
            for (int element_index = 0; element_index < 4; element_index++)
            {
                result.elements[row][col] = a.elements[row][element_index] * b.elements[element_index][col];
            }
        }
    }
    
    return result;
}

inline mat4
mat4_transpose(mat4 m)
{
    mat4 result;

    for (int row = 0; row < 4; ++row)
    {
        for (int col = 0; col < 4; ++col)
        {
            result.elements[row][col] = m.elements[col][row];
        }
    }
    
    return result;
}

inline mat4
mat4_scale(vec3 v)
{
    mat4 result = mat4_identity();

    result._11 = v.x;
    result._22 = v.y;
    result._33 = v.z;

    return result;
}

inline mat4
mat4_scale(float v)
{
    mat4 result = mat4_identity();

    result._11 = v;
    result._22 = v;
    result._33 = v;

    return result;
}

inline mat4
mat4_translation(vec3 v)
{
    mat4 result = mat4_identity();

    result._14 = v.x;
    result._24 = v.y;
    result._34 = v.z;

    return result;
}

inline mat4
mat4_x_rotation(float phi)
{
    mat4 result = mat4_identity();

    float cp = cosf(phi);
    float sp = sinf(phi);
    
    result._22 = cp;
    result._23 = -sp;
    result._32 = sp;
    result._33 = cp;

    return result;
}

inline mat4
mat4_y_rotation(float phi)
{
    mat4 result = mat4_identity();

    float cp = cosf(phi);
    float sp = sinf(phi);
    
    result._11 = cp;
    result._13 = sp;
    result._31 = -sp;
    result._33 = cp;

    return result;
}

inline mat4
mat4_z_rotation(float phi)
{
    mat4 result = mat4_identity();
    
    float cp = cosf(phi);
    float sp = sinf(phi);
    
    result._11 = cp;
    result._12 = -sp;
    result._21 = sp;
    result._22 = cp;

    return result;
}

struct quaternion
{
    float w;
    float x;
    float y;
    float z;
};

inline quaternion
quaternion_identity(void)
{
    quaternion result;

    result.w = 1.0f;
    result.x = 0.0f;
    result.y = 0.0f;
    result.z = 0.0f;

    return result;
}

inline void
set_quaternion(quaternion *q, float w, float x, float y, float z)
{
    q->w = w;
    q->x = x;
    q->y = y;
    q->z = z;
}

inline void
set_quaternion_from_axis_and_angle(quaternion *q, vec3 axis, float angle)
{
    float cha = cosf(0.5f * angle);
    float sha = sinf(0.5f * angle);
    
    q->w = cha;
    q->x = axis.x * sha;
    q->y = axis.y * sha;
    q->z = axis.z * sha;
}

inline quaternion
operator-(quaternion a)
{
    quaternion result;

    result.x = -a.x;
    result.y = -a.y;
    result.z = -a.z;
    result.w = -a.w;

    return result;
}

inline quaternion
operator+(quaternion a, quaternion b)
{
    quaternion result;

    // Real part
    result.w = a.w + b.w;

    // Imaginary part
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    
    return result;
}

inline quaternion
operator-(quaternion a, quaternion b)
{
    quaternion result;

    // Real part
    result.w = a.w - b.w;

    // Imaginary part
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    
    return result;
}

inline quaternion
operator*(quaternion a, quaternion b)
{
    quaternion result;

    result.w = a.w*b.w - a.x*b.x - a.y*b.y - a.z*b.z;
    result.x = a.x*b.w + a.w*b.x + a.y*b.z - a.z*b.y;
    result.y = a.w*b.y - a.x*b.z + a.y*b.w + a.w*b.x;
    result.z = a.w*b.z + a.x*b.y - a.y*b.x + a.z*b.w;
    
    return result;
}

inline quaternion
conjugate(quaternion q)
{
    quaternion result;

    result.w = q.w;
    result.x = -q.x;
    result.y = -q.y;
    result.z = -q.z;

    return result;
}

inline quaternion
negate(quaternion q)
{
    quaternion result;

    result.w = -q.w;
    result.x = -q.x;
    result.y = -q.y;
    result.z = -q.z;

    return result;
}

inline float
length_squared(quaternion q)
{
    float result = q.x*q.x + q.y*q.y + q.z*q.z + q.w*q.w;
    return result;
}

inline float
length(quaternion q)
{
    float len_sq = length_squared(q);
    float result = sqrtf(len_sq);
    return result;
}

inline quaternion
normalize_or_zero(quaternion q)
{
    quaternion result = {};

    float len_sq = length_squared(q);
    if (len_sq > SQUARE(0.001f))
    {
        float len = sqrtf(len_sq);
        float inv_len = 1.0f / len;

        result.w *= inv_len;
        result.x *= inv_len;
        result.y *= inv_len;
        result.z *= inv_len;
    }

    return result;
}

inline quaternion
normalize_or_identity(quaternion q)
{
    quaternion result = quaternion_identity();
    
    float len_sq = length_squared(q);
    if (len_sq > SQUARE(0.001f))
    {
        float len = sqrtf(len_sq);
        float inv_len = 1.0f / len;

        result.w *= inv_len;
        result.x *= inv_len;
        result.y *= inv_len;
        result.z *= inv_len;
    }

    return result;
}

// http://www.songho.ca/opengl/gl_quaternion.html
inline mat4
quaternion_to_matrix(quaternion q)
{
    mat4 result = mat4_identity();

    float x_sq = SQUARE(q.x);
    float y_sq = SQUARE(q.y);
    float z_sq = SQUARE(q.z);

    float xw = q.x*q.w;
    float yw = q.y*q.w;
    float zw = q.z*q.w;

    float xy = q.x*q.y;
    float xz = q.x*q.z;
    float yz = q.y*q.z;
    
    result._11 = 1 - (2.0f*y_sq) - (2.0f*z_sq);
    result._12 = 2.0f*xy - 2.0f*xw;
    result._13 = 2.0f*xz + 2.0f*yw;

    result._21 = 2.0f*xy + 2.0f*zw;
    result._22 = 1.0f - 2.0f*x_sq - 2.0f*z_sq;
    result._23 = 2.0f*yz - 2.0f*xw;

    result._31 = 2.0f*xz - 2.0f*xy;
    result._32 = 2.0f*yz + 2.0f*xw;
    result._33 = 1.0f - 2.0f*x_sq - 2.0f*y_sq;
    
    return result;
}

#endif
