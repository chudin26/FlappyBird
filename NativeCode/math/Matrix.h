//
//  Matrix.h
//  FlappyBird
//
//  Created by Yuriy Chudin on 07.12.16.
//  Copyright © 2016 Yuriy Chudin. All rights reserved.
//

#pragma once

#include "Vec3.h"
#include <cstring>
#include <math.h>

namespace math {
	
	struct Matrix {
		
		float m[16];
		
		float& rc(int row, int column) {
			return m[row * 4 + column];
		}

		const float& rc(int row, int column) const {
			return m[row * 4 + column];
		}
		
		static Matrix frustum(float left, float right, float bottom, float top, float near, float far) {
			Matrix result;
			
			result.m[0] = (2.0 * near) / (right - left);
			result.m[1] = 0.0;
			result.m[2] = 0.0;
			result.m[3] = 0.0;
			
			result.m[4] = 0.0;
			result.m[5] = (2.0 * near) / (top - bottom);
			result.m[6] = 0.0;
			result.m[7] = 0.0;
			
			result.m[8]  = (right + left) / (right - left);
			result.m[9]  = (top + bottom) / (top - bottom);
			result.m[10] = -(far + near) / (far - near);
			result.m[11] = -1.0;
			
			result.m[12] = 0.0;
			result.m[13] = 0.0;
			result.m[14] = -(2.0 * far * near) / (far - near);
			result.m[15] = 0.0;
			
			return result;
		}
		
		static Matrix identity() {
			Matrix result;
			std::memset(result.m, 0.0f, sizeof(float) * 16);
			
			result.m[0] = 1.0f;
			result.m[5] = 1.0f;
			result.m[10] = 1.0f;
			result.m[15] = 1.0f;
			
			return result;
		}
		
		static Matrix translation(const Vec3f &pos) {
			Matrix result = identity();
			result.m[12] = pos.x;
			result.m[13] = pos.y;
			result.m[14] = pos.z;
			
			return result;
		}

		static Matrix scale(const Vec3f &scale) {
			Matrix result;
			std::memset(result.m, 0.0f, sizeof(float) * 16);
			
			result.m[0] = scale.x;
			result.m[5] = scale.y;
			result.m[10] = scale.z;
			result.m[15] = 1.0f;
			
			return result;
		}
		
		static Matrix rotation(const Vec3f &angles) {
			float cz = cosf(angles.z);
			float sz = sinf(angles.z);
			float cy = cosf(angles.y);
			float sy = sinf(angles.y);
			float cx = cosf(angles.x);
			float sx = sinf(angles.x);
			
			Matrix result;
			result.m[0] = cz * cy;
			result.m[1] = -cz * sx * sy - sz * cx;
			result.m[2] = -cz * cx * sy + sz * sx;
			result.m[3] = 0.0f;
			result.m[4] = sz * cy;
			result.m[5] = -sz * sx * sy + cz * cx;
			result.m[6] = -sz * cx * sy - cz * sx;
			result.m[7] = 0.0f;
			result.m[8] = sy;
			result.m[9] = sx * cy;
			result.m[10] = cx * cy;
			result.m[11] = 0.0f;
			result.m[12] = 0.0f;
			result.m[13] = 0.0f;
			result.m[14] = 0.0f;
			result.m[15] = 1.0f;
			
			return result;
		}
		
		Matrix inverse() const {
			Matrix res = identity();
			Matrix m = *this;
			for (int i = 0; i < 4; ++i) {
				int ma = i;
				for (int j = ma + 1; j < 4; ++j)
					if (fabs(m.rc(j, i)) > fabs(m.rc(ma, i)))
						ma = j;
				
				if (ma != i)
					for (int nx = 0; nx < 4; ++nx) {
						float tmp = m.rc(i, nx);
						m.rc(i, nx) = m.rc(ma, nx);
						m.rc(ma, nx) = tmp;
						tmp = res.rc(i, nx);
						res.rc(i, nx) = res.rc(ma, nx);
						res.rc(ma, nx) = tmp;
					}
				
				for (int ny = 0; ny < 4; ++ny)
					if (ny == i) {
						float mul = 1 / m.rc(i, i);
						for (int nx = 0; nx < 4; ++nx) {
							m.rc(ny, nx) *= mul;
							res.rc(ny, nx) *= mul;
						}
					} else {
						float mul = m.rc(ny, i) / m.rc(i, i);
						for (int nx = 0; nx < 4; ++nx) {
							m.rc(ny, nx) -= mul * m.rc(i, nx);
							res.rc(ny, nx) -= mul * res.rc(i, nx);
						}
					}
			}
			
			return res;
		}
		
	};

	inline Matrix operator * (const Matrix& m1, const Matrix& m2) {
		Matrix result;
		
		for (int row = 0; row < 4; ++row) {
			for (int column = 0; column < 4; ++column) {
				float sum = 0.0f;
				for (int i = 0; i < 4; ++i) {
					sum += m1.rc(row, i) * m2.rc(i, column);
				}
				
				result.rc(row, column) = sum;
			}
		}
		
		return result;
	}
	
	inline Vec3f operator * (const Vec3f& v, const Matrix& m) {
		float c[4];
		for (int i = 0; i < 4; i++) {
//			c[i] = m.rc(i, 0) * v.x + m.rc(i, 1) * v.y + m.rc(i, 2) * v.z + m.rc(i, 3);
			c[i] = m.rc(0, i) * v.x + m.rc(1, i) * v.y + m.rc(2, i) * v.z + m.rc(3, i);
		}
		
		return Vec3f(c[0] / c[3], c[1] / c[3], c[2] / c[3]);
	}
	
}
