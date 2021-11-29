#include "pch.h"
//#define _USE_MATH_DEFINES
//#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>  
#include "utils.h"
#include <math.h>

namespace utils
{
#pragma region OpenGLDrawFunctionality
	void ClearBackground(float r, float g, float b)
	{
		glClearColor(r, g, b, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	void ClearBackground()
	{
		ClearBackground(185.0f / 255.0f, 211.0f / 255.0f, 238.0f / 255.0f);
	}
	void SetColor(float r, float g, float b, float a)
	{
		glColor4f(r, g, b, a);
	}

	void SetColor(const Color4f& color)
	{
		glColor4f(color.r, color.g, color.b, color.a);
	}

	void DrawLine(float x1, float y1, float x2, float y2, float lineWidth)
	{
		glLineWidth(lineWidth);
		glBegin(GL_LINES);
		{
			glVertex2f(x1, y1);
			glVertex2f(x2, y2);
		}
		glEnd();
	}

	void DrawLine(const Point2f& p1, const Point2f& p2, float lineWidth)
	{
		DrawLine(p1.x, p1.y, p2.x, p2.y, lineWidth);
	}

	void DrawRect(float left, float bottom, float width, float height, float lineWidth)
	{
		glLineWidth(lineWidth);
		glBegin(GL_LINE_LOOP);
		{
			glVertex2f(left, bottom);
			glVertex2f(left + width, bottom);
			glVertex2f(left + width, bottom + height);
			glVertex2f(left, bottom + height);
		}
		glEnd();
	}

	void DrawTriangle(const Point2f& p1, const Point2f& p2, const Point2f& p3, float lineWidth)
	{
		glLineWidth(lineWidth);
		glBegin(GL_LINE_LOOP);
		{
			glVertex2f(p1.x, p1.y);
			glVertex2f(p2.x, p2.y);
			glVertex2f(p3.x, p3.y);
		}
		glEnd();
	}

	void FillTriangle(const Point2f& p1, const Point2f& p2, const Point2f& p3)
	{
		glBegin(GL_TRIANGLES);
		{
			glVertex2f(p1.x, p1.y);
			glVertex2f(p2.x, p2.y);
			glVertex2f(p3.x, p3.y);
		}
		glEnd();
	}

	void DrawRect(const Point2f& bottomLeft, float width, float height, float lineWidth)
	{
		DrawRect(bottomLeft.x, bottomLeft.y, width, height, lineWidth);
	}

	void DrawRect(const Rectf& rect, float lineWidth)
	{
		DrawRect(rect.left, rect.bottom, rect.width, rect.height, lineWidth);
	}

	void FillRect(float left, float bottom, float width, float height)
	{
		glBegin(GL_POLYGON);
		{
			glVertex2f(left, bottom);
			glVertex2f(left + width, bottom);
			glVertex2f(left + width, bottom + height);
			glVertex2f(left, bottom + height);
		}
		glEnd();
	}

	void FillRect(const Point2f& bottomLeft, float width, float height)
	{
		FillRect(bottomLeft.x, bottomLeft.y, width, height);
	}

	void FillRect(const Rectf& rect)
	{
		FillRect(rect.left, rect.bottom, rect.width, rect.height);
	}

	void DrawEllipse(float centerX, float centerY, float radX, float radY, float lineWidth)
	{
		float dAngle{ radX > radY ? float(g_Pi / radX) : float(g_Pi / radY) };

		glLineWidth(lineWidth);
		glBegin(GL_LINE_LOOP);
		{
			for (float angle = 0.0; angle < float(2 * g_Pi); angle += dAngle)
			{
				glVertex2f(centerX + radX * float(cos(angle)), centerY + radY * float(sin(angle)));
			}
		}
		glEnd();
	}

	void DrawEllipse(const Point2f& center, float radX, float radY, float lineWidth)
	{
		DrawEllipse(center.x, center.y, radX, radY, lineWidth);
	}

	void DrawEllipse(const Ellipsef& ellipse, float lineWidth)
	{
		DrawEllipse(ellipse.center.x, ellipse.center.y, ellipse.radiusX, ellipse.radiusY, lineWidth);
	}

	void FillEllipse(float centerX, float centerY, float radX, float radY)
	{
		float dAngle{ radX > radY ? float(g_Pi / radX) : float(g_Pi / radY) };

		glBegin(GL_POLYGON);
		{
			for (float angle = 0.0; angle < float(2 * g_Pi); angle += dAngle)
			{
				glVertex2f(centerX + radX * float(cos(angle)), centerY + radY * float(sin(angle)));
			}
		}
		glEnd();
	}

	void FillEllipse(const Ellipsef& ellipse)
	{
		FillEllipse(ellipse.center.x, ellipse.center.y, ellipse.radiusX, ellipse.radiusY);
	}

	void FillEllipse(const Point2f& center, float radX, float radY)
	{
		FillEllipse(center.x, center.y, radX, radY);
	}

	void DrawArc(float centerX, float centerY, float radX, float radY, float fromAngle, float tillAngle, float lineWidth)
	{
		if (fromAngle > tillAngle)
		{
			return;
		}

		float dAngle{ radX > radY ? float(g_Pi / radX) : float(g_Pi / radY) };

		glLineWidth(lineWidth);
		glBegin(GL_LINE_STRIP);
		{
			for (float angle = fromAngle; angle < tillAngle; angle += dAngle)
			{
				glVertex2f(centerX + radX * float(cos(angle)), centerY + radY * float(sin(angle)));
			}
			glVertex2f(centerX + radX * float(cos(tillAngle)), centerY + radY * float(sin(tillAngle)));
		}
		glEnd();

	}

	void DrawArc(const Point2f& center, float radX, float radY, float fromAngle, float tillAngle, float lineWidth)
	{
		DrawArc(center.x, center.y, radX, radY, fromAngle, tillAngle, lineWidth);
	}

	void FillArc(float centerX, float centerY, float radX, float radY, float fromAngle, float tillAngle)
	{
		if (fromAngle > tillAngle)
		{
			return;
		}
		float dAngle{ radX > radY ? float(g_Pi / radX) : float(g_Pi / radY) };

		glBegin(GL_POLYGON);
		{
			glVertex2f(centerX, centerY);
			for (float angle = fromAngle; angle < tillAngle; angle += dAngle)
			{
				glVertex2f(centerX + radX * float(cos(angle)), centerY + radY * float(sin(angle)));
			}
			glVertex2f(centerX + radX * float(cos(tillAngle)), centerY + radY * float(sin(tillAngle)));
		}
		glEnd();
	}

	void FillArc(const Point2f& center, float radX, float radY, float fromAngle, float tillAngle)
	{
		FillArc(center.x, center.y, radX, radY, fromAngle, tillAngle);
	}

	void DrawPolygon(const std::vector<Point2f>& vertices, bool closed, float lineWidth)
	{
		DrawPolygon(vertices.data(), vertices.size(), closed, lineWidth);
	}

	void DrawPolygon(const Point2f* pVertices, size_t nrVertices, bool closed, float lineWidth)
	{
		glLineWidth(lineWidth);
		closed ? glBegin(GL_LINE_LOOP) : glBegin(GL_LINE_STRIP);
		{
			for (size_t idx{ 0 }; idx < nrVertices; ++idx)
			{
				glVertex2f(pVertices[idx].x, pVertices[idx].y);
			}
		}
		glEnd();
	}

	void FillPolygon(const std::vector<Point2f>& vertices)
	{
		FillPolygon(vertices.data(), vertices.size());
	}

	void FillPolygon(const Point2f* pVertices, size_t nrVertices)
	{
		glBegin(GL_POLYGON);
		{
			for (size_t idx{ 0 }; idx < nrVertices; ++idx)
			{
				glVertex2f(pVertices[idx].x, pVertices[idx].y);
			}
		}
		glEnd();
	}
#pragma endregion OpenGLDrawFunctionality


#pragma region textureImplementations

	bool TextureFromFile(const std::string& path, Texture& texture)
	{
		//Load file for use as an image in a new surface.
		SDL_Surface* pLoadedSurface = IMG_Load(path.c_str());
		if (pLoadedSurface == nullptr)
		{
			std::cerr << "TextureFromFile: SDL Error when calling IMG_Load: " << SDL_GetError() << std::endl;
			return false;
		}

		TextureFromSurface(pLoadedSurface, texture);

		//Free loaded surface
		SDL_FreeSurface(pLoadedSurface);

		return true;
	}

	bool TextureFromString(const std::string& text, const std::string& fontPath, int ptSize, const Color4f& textColor, Texture& texture)
	{
		// Create font
		TTF_Font* pFont{};
		pFont = TTF_OpenFont(fontPath.c_str(), ptSize);
		if (pFont == nullptr)
		{
			std::cout << "TextureFromString: Failed to load font! SDL_ttf Error: " << TTF_GetError();
			std::cin.get();
			return false;
		}

		// Create texture using this fontand close font afterwards
		bool textureOk = TextureFromString(text, pFont, textColor, texture);
		TTF_CloseFont(pFont);

		return textureOk;
	}

	bool TextureFromString(const std::string& text, TTF_Font* pFont, const Color4f& color, Texture& texture)
	{
		//Render text surface
		SDL_Color textColor{};
		textColor.r = Uint8(color.r * 255);
		textColor.g = Uint8(color.g * 255);
		textColor.b = Uint8(color.b * 255);
		textColor.a = Uint8(color.a * 255);

		SDL_Surface* pLoadedSurface = TTF_RenderText_Blended(pFont, text.c_str(), textColor);
		//SDL_Surface* pLoadedSurface = TTF_RenderText_Solid(pFont, textureText.c_str(), textColor);
		if (pLoadedSurface == nullptr)
		{
			std::cerr << "TextureFromString: Unable to render text surface! SDL_ttf Error: " << TTF_GetError() << '\n';
			return false;
		}

		// copy to video memory
		TextureFromSurface(pLoadedSurface, texture);

		//Free loaded surface
		SDL_FreeSurface(pLoadedSurface);

		return true;
	}

	void TextureFromSurface(const SDL_Surface* pSurface, Texture& texture)
	{
		//Get image dimensions
		texture.width = float(pSurface->w);
		texture.height = float(pSurface->h);

		// Get pixel format information and translate to OpenGl format
		GLenum pixelFormat{ GL_RGB };
		switch (pSurface->format->BytesPerPixel)
		{
		case 3:
			if (pSurface->format->Rmask == 0x000000ff)
			{
				pixelFormat = GL_RGB;
			}
			else
			{
				pixelFormat = GL_BGR;
			}
			break;
		case 4:
			if (pSurface->format->Rmask == 0x000000ff)
			{
				pixelFormat = GL_RGBA;
			}
			else
			{
				pixelFormat = GL_BGRA;
			}
			break;
		default:
			std::cerr << "TextureFromSurface error: Unknow pixel format, BytesPerPixel: " << pSurface->format->BytesPerPixel << "\nUse 32 bit or 24 bit images.\n";;
			texture.width = 0;
			texture.height = 0;
			return;
		}

		//Generate an array of textures.  We only want one texture (one element array), so trick
		//it by treating "texture" as array of length one.
		glGenTextures(1, &texture.id);

		//Select (bind) the texture we just generated as the current 2D texture OpenGL is using/modifying.
		//All subsequent changes to OpenGL's texturing state for 2D textures will affect this texture.
		glBindTexture(GL_TEXTURE_2D, texture.id);

		// check for errors.
		GLenum e = glGetError();
		if (e != GL_NO_ERROR)
		{
			std::cerr << "TextureFromSurface, error binding textures, Error id = " << e << '\n';
			texture.width = 0;
			texture.height = 0;
			return;
		}

		//Specify the texture's data.  This function is a bit tricky, and it's hard to find helpful documentation.  A summary:
		//   GL_TEXTURE_2D:    The currently bound 2D texture (i.e. the one we just made)
		//               0:    The mipmap level.  0, since we want to update the base level mipmap image (i.e., the image itself,
		//                         not cached smaller copies)
		//         GL_RGBA:    Specifies the number of color components in the texture.
		//                     This is how OpenGL will store the texture internally (kinda)--
		//                     It's essentially the texture's type.
		//      surface->w:    The width of the texture
		//      surface->h:    The height of the texture
		//               0:    The border.  Don't worry about this if you're just starting.
		//     pixelFormat:    The format that the *data* is in--NOT the texture! 
		//GL_UNSIGNED_BYTE:    The type the data is in.  In SDL, the data is stored as an array of bytes, with each channel
		//                         getting one byte.  This is fairly typical--it means that the image can store, for each channel,
		//                         any value that fits in one byte (so 0 through 255).  These values are to be interpreted as
		//                         *unsigned* values (since 0x00 should be dark and 0xFF should be bright).
		// surface->pixels:    The actual data.  As above, SDL's array of bytes.
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, pSurface->w, pSurface->h, 0, pixelFormat, GL_UNSIGNED_BYTE, pSurface->pixels);

		//Set the minification and magnification filters.  In this case, when the texture is minified (i.e., the texture's pixels (texels) are
		//*smaller* than the screen pixels you're seeing them on, linearly filter them (i.e. blend them together).  This blends four texels for
		//each sample--which is not very much.  Mipmapping can give better results.  Find a texturing tutorial that discusses these issues
		//further.  Conversely, when the texture is magnified (i.e., the texture's texels are *larger* than the screen pixels you're seeing
		//them on), linearly filter them.  Qualitatively, this causes "blown up" (overmagnified) textures to look blurry instead of blocky.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	}

	void DeleteTexture(Texture& texture)
	{
		glDeleteTextures(1, &texture.id);
	}

	void DrawTexture(const Texture& texture, const Point2f& dstBottomLeft, const Rectf& srcRect)
	{
		Rectf dstRect{ dstBottomLeft.x, dstBottomLeft.y, srcRect.width, srcRect.height };
		DrawTexture(texture, dstRect, srcRect);
	}


	void DrawTexture(const Texture& texture, const Rectf& dstRect, const Rectf& srcRect)
	{
		// Determine texture coordinates using srcRect and default destination width and height
		float textLeft{};
		float textRight{};
		float textTop{};
		float textBottom{};

		float defaultDstWidth{};
		float defaultDstHeight{};
		if (!(srcRect.width > 0.0f && srcRect.height > 0.0f)) // No srcRect specified
		{
			// Use complete texture
			textLeft = 0.0f;
			textRight = 1.0f;
			textTop = 0.0f;
			textBottom = 1.0f;

			defaultDstHeight = texture.height;
			defaultDstWidth = texture.width;
		}
		else // srcRect specified
		{
			// Convert to the range [0.0, 1.0]
			textLeft = srcRect.left / texture.width;
			textRight = (srcRect.left + srcRect.width) / texture.width;
			textTop = (srcRect.bottom - srcRect.height) / texture.height;
			textBottom = srcRect.bottom / texture.height;

			defaultDstHeight = srcRect.height;
			defaultDstWidth = srcRect.width;
		}

		// Determine vertex coordinates
		float vertexLeft{ dstRect.left };
		float vertexBottom{ dstRect.bottom };
		float vertexRight{};
		float vertexTop{};
		if (!(dstRect.width > 0.0f && dstRect.height > 0.0f)) // If no size specified use default size
		{
			vertexRight = vertexLeft + defaultDstWidth;
			vertexTop = vertexBottom + defaultDstHeight;
		}
		else
		{
			vertexRight = vertexLeft + dstRect.width;
			vertexTop = vertexBottom + dstRect.height;
		}

		// Tell opengl which texture we will use
		glBindTexture(GL_TEXTURE_2D, texture.id);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

		// set the texture mode https://open.gl/textures
		float color[] = { 1.0f, 0.0f, 1.0f, 1.0f };
		glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
		// Draw
		glEnable(GL_TEXTURE_2D);
		{
			glBegin(GL_QUADS);
			{
				glTexCoord2f(textLeft, textBottom);
				glVertex2f(vertexLeft, vertexBottom);

				glTexCoord2f(textLeft, textTop);
				glVertex2f(vertexLeft, vertexTop);

				glTexCoord2f(textRight, textTop);
				glVertex2f(vertexRight, vertexTop);

				glTexCoord2f(textRight, textBottom);
				glVertex2f(vertexRight, vertexBottom);
			}
			glEnd();
		}
		glDisable(GL_TEXTURE_2D);

	}
#pragma endregion textureImplementations


#pragma region CollisionFunctionality

	// Calculates and returns the distance between two points using floats
	float GetDistance(const float x1, const float y1, const float x2, const float y2)
	{
		float distance{};
		float lengthX{};
		float lengthY{};

		// We apply pythagoras theorem  
		lengthX = x2 - x1;
		lengthX *= lengthX;

		lengthY = y2 - y1;
		lengthY *= lengthY;

		// Square root of the adittion of the results
		distance = sqrt(lengthX + lengthY);

		return distance;

	}
	// Calculates and returns the distance between two points using Point2f struct
	float GetDistance(const Point2f& p1, const Point2f& p2)
	{
		float distance{};
		float lengthX{};
		float lengthY{};

		// We apply pythagoras theorem  
		lengthX = p2.x - p1.x;
		lengthX *= lengthX;
		// Y value
		lengthY = p2.y - p1.y;
		lengthY *= lengthY;

		// Square root of the adittion of the results
		distance = sqrt(lengthX + lengthY);

		//std::cout << distance << std::endl;

		return distance;
	}
	// Check if the point is inside the radius of the circle
	bool IsPointInCircle(const Point2f& p1, const Circlef& circle)
	{
		bool inCircle{};  // 0 --> False
		float distance{};

		// Calculate distance between point and center of circle
		distance = GetDistance(p1, circle.center);

		if (distance <= circle.radius)
		{
			// Point inside the circle
			inCircle = true;
		}

		return inCircle;
	}

	// Check if the point is inside the rectangle
	bool IsPointInRect(const Point2f& p1, const Rectf& rectangle)
	{
		bool inRect{};  // 0 --> False
		

		if (p1.x >= rectangle.left && p1.x <= rectangle.left + rectangle.width)
		{
			if (p1.y >= rectangle.bottom && p1.y <= rectangle.bottom + rectangle.height)
			{
				// Point inside rect
				inRect = true;
			}
		}
		
		return inRect;
	}

	bool IsOverlapping(const Rectf& rect1, const Rectf& rect2)
	{
		bool overlapping{ true }; 

		// Top left coord of rect1
		Point2f l1{ rect1.left, rect1.bottom + rect1.height}; 
		// Right bottom cord of rect1
		Point2f r1{ rect1.left + rect1.width, rect1.bottom };

		// Rect 2 coord (top left and right bottom
		Point2f l2{ rect2.left, rect2.bottom + rect2.height };
		Point2f r2{ rect2.left + rect2.width, rect2.bottom };


		// If one of these conditions are true --> Overlapping == false
		
		// If one rectangle is on left side of the other
		if (l1.x > r2.x || l2.x > r1.x)
			overlapping = false;
		// If one rectangle is on above the other
		if (r1.y > l2.y || r2.y > l1.y)
			overlapping = false;


		return overlapping;
	}

	bool IsOverlapping(const Circlef& circle1, const Circlef& circle2)
	{
		bool overlapping{  }; 
		float distance{}, sumRadi{}, subtRadi{};

		// Distance between the centers of the cirlce
		distance = utils::GetDistance(circle1.center, circle2.center);

		sumRadi = circle1.radius + circle2.radius;		// Both radius added (two circles touch externally)
		subtRadi = circle1.radius - circle2.radius;		// Both radius subtracted (two circles touch internally)

		if (subtRadi < distance  && distance < sumRadi)
		{
			// Circles will intersect
			overlapping = true;
		}
		

		return overlapping;
	}


#pragma endregion CollisionFunctionality

#pragma region VectorFunctionality

	// Draw a vector as a line between the start point and the vector parameter.
	// Also draws a filled triangle at the end (30 degrees)
	void DrawVector(const Vector2f& vector, const Point2f& startPoint)
	{
		Point2f endPoint{ startPoint.x + vector.x, startPoint.y + vector.y };

		// Line from starting point to endingPoint
		utils::DrawLine(startPoint, endPoint);

		// Filled equilateral triangle (30 degrees).
		// We have to get the angle between the vector and the horizontal x
		// After ypu get the points of the triangle subtracting and adding that angle 

					

		//FillTriangle(p1, p2, p3);

	}

	// Return a string with the values of the vector
	std::string ToString(const Vector2f& vector)
	{
		std::string stringV{};

		stringV = "[" + std::to_string(vector.x) + ", " + std::to_string(vector.y) + "]";
	
		return stringV;
	}

	// Add two vectors and return the result vector
	Vector2f Add(const Vector2f& v1, const Vector2f& v2)
	{
		Vector2f vectorSum{};

		// Addition of the components of both vectors
		vectorSum.x = v1.x + v2.x;
		vectorSum.y = v1.y + v2.y;


		//std::cout << vectorSum.x << std::endl;
		//std::cout << vectorSum.y << std::endl;

		return vectorSum;
	}

	// Subtract two vectors and return the result vector
	Vector2f Subtract(const Vector2f& v1, const Vector2f& v2)
	{
		Vector2f vectorSub{};

		vectorSub.x = v1.x - v2.x;
		vectorSub.y = v1.y - v2.y;

		return vectorSub;

	}
	// Calculates the dot product of two vectors
	float DotProduct(const Vector2f& v1, const Vector2f& v2)
	{
		float vectorDot{};

		// Multiply components of both vectors and add them. Result is a scalar
		vectorDot = (v1.x * v2.x) + (v1.y * v2.y);
		
		return vectorDot;
	}

	// Calculates the cross product of two vectors with Z-component=0
	float CrossProduct(const Vector2f& v1, const Vector2f& v2)
	{
		float lengthZ{};

		// Cross product is for 3D vectors only, so the Z-Component is 0 here
		// The result of the cross product for the X and Y components are going to be 0
		// So we only calculate the component for the  Z-axis
		lengthZ = (v1.x*v2.y) - (v1.y*v2.x);	/// Z-component

		return lengthZ;
	}

	// Calculates the length of the vector using pithagoras
	float Length(const Vector2f& v)
	{
		float length{};

		// Pithagoras Theorem
		length = sqrt((v.x * v.x) + (v.y * v.y));

		return length;
	}

	// Returns a scaled vector by the result of multiplicate a scalar to the vector
	Vector2f Scale(const Vector2f& v, float scalar)
	{
		Vector2f scaledV{};

		// New scaled vector
		scaledV.x = scalar * v.x;
		scaledV.y = scalar * v.y;

		return scaledV;
	}
	// Returns a normalized vector
	Vector2f Normalize(const Vector2f& v)
	{
		Vector2f normalizedV{};
		float length;

		// Calculate length of the vector
		length = Length(v);

		// Divide the components by the length of the vector --> Normalized vector
		normalizedV.x = v.x / length;
		normalizedV.y = v.y / length;

		return normalizedV;
	}

	// Calculates the angle between two given vectors using the atan2 function
	float AngleBetween(const Vector2f& v1, const Vector2f& v2)
	{
		float angle{}, dot{}, cross{};

		cross = CrossProduct(v1, v2);
		dot = DotProduct(v1, v2);

		// Inverse tangent of cross/dot gives the angle between
		angle = atan2(cross, dot);

		return angle;
		
	}

	// Check if both vectors are equal(almost (same length and direction)
	bool AreEqual(const Vector2f& v1, const Vector2f& v2)
	{
		bool equals{};

		if (abs(Length(v1) - Length(v2)) <= 0.001f)
		{
			// Both vectors have the same length

			if (abs(v1.x - v2.x) <= 0.001f && abs(v1.y - v2.y) <= 0.001f)
			{
				// Both vectors also have the same direction
				equals = true;
			}
		}
		return equals;
	}
	





#pragma endregion VectorFunctionality
}