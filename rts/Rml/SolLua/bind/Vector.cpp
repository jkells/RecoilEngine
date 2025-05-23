/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

/*
 * This source file is derived from the code
 * at https://github.com/LoneBoco/RmlSolLua
 * which is under the following license:
 *
 * MIT License
 *
 * Copyright (c) 2022 John Norman
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include "bind.h"


namespace Rml::SolLua
{

	void bind_vector(sol::table& namespace_table)
	{
		/***
		 * Two-dimensional integral vector.
		 * @class RmlUi.Vector2i
		 * @operator add:RmlUi.Vector2i
		 * @operator div:RmlUi.Vector2i
		 * @operator mul:RmlUi.Vector2i
		 * @operator sub:RmlUi.Vector2i
		 * @operator unm:RmlUi.Vector2i
		 */

		 
		namespace_table.new_usertype<Rml::Vector2i>("Vector2i", 
			/***
			 * @function RmlUi.Vector2i.new
			 * @param x integer
			 * @param y integer
			 * @return RmlUi.Vector2i
			 */
			sol::constructors<Rml::Vector2i(), Rml::Vector2i(int, int)>(),
			// O
			sol::meta_function::addition, &Rml::Vector2i::operator+,
			sol::meta_function::subtraction, sol::resolve<Rml::Vector2i(Vector2i) const>(&Rml::Vector2i::operator-),
			sol::meta_function::multiplication, sol::overload(
				sol::resolve<Rml::Vector2i(int) const>(&Rml::Vector2i::operator*),
				sol::resolve<Rml::Vector2i(Rml::Vector2i) const>(&Rml::Vector2i::operator*)
			),
			sol::meta_function::division, sol::overload(
				sol::resolve<Rml::Vector2i(int) const>(&Rml::Vector2i::operator/),
				sol::resolve<Rml::Vector2i(Rml::Vector2i) const>(&Rml::Vector2i::operator/)
			),
			sol::meta_function::unary_minus, sol::resolve<Rml::Vector2i() const>(&Rml::Vector2i::operator-),

			// G+S
			/*** @field RmlUi.Vector2i.x integer */
			"x", &Rml::Vector2i::x,
			/*** @field RmlUi.Vector2i.y integer */
			"y", &Rml::Vector2i::y,

			// G
			/*** @field RmlUi.Vector2i.magnitude number */
			"magnitude", &Rml::Vector2i::Magnitude
		);

		/***
		 * Two-dimensional float vector
		 * @see float2
		 * @class RmlUi.Vector2f
		 * @operator add:RmlUi.Vector2f
		 * @operator div:RmlUi.Vector2f
		 * @operator mul:RmlUi.Vector2f
		 * @operator sub:RmlUi.Vector2f
		 * @operator unm:RmlUi.Vector2i
		 */
		
		namespace_table.new_usertype<Rml::Vector2f>("Vector2f", 
			/***
			 * @function RmlUi.Vector2f.new
			 * @param x number
			 * @param y number
			 * @return RmlUi.Vector2f
			 */
			sol::constructors<Rml::Vector2f(), Rml::Vector2f(float, float)>(),
			// O
			sol::meta_function::addition, &Rml::Vector2f::operator+,
			sol::meta_function::subtraction, sol::resolve<Rml::Vector2f(Vector2f) const>(&Rml::Vector2f::operator-),
			sol::meta_function::multiplication, sol::overload(
				sol::resolve<Rml::Vector2f(float) const>(&Rml::Vector2f::operator*),
				sol::resolve<Rml::Vector2f(Rml::Vector2f) const>(&Rml::Vector2f::operator*)
			),
			sol::meta_function::division, sol::overload(
				sol::resolve<Rml::Vector2f(float) const>(&Rml::Vector2f::operator/),
				sol::resolve<Rml::Vector2f(Rml::Vector2f) const>(&Rml::Vector2f::operator/)
			),
			sol::meta_function::unary_minus, sol::resolve<Rml::Vector2f() const>(&Rml::Vector2f::operator-),

			// G+S
			/*** @field RmlUi.Vector2f.x number */
			"x", &Rml::Vector2f::x,
			/*** @field RmlUi.Vector2f.y number */
			"y", &Rml::Vector2f::y,

			// G
			/*** @field RmlUi.Vector2f.magnitude number */
			"magnitude", &Rml::Vector2f::Magnitude
		);
	}

} // end namespace Rml::SolLua
