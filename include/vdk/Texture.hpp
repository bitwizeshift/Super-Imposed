/**
 * @file Texture.hpp
 *
 * @todo Add description
 *
 * @author Matthew Rodusek (matthew.rodusek@gmail.com)
 * @date   Feb 8, 2016
 *
 */

/*
 * Change Log:
 *
 * Feb 8, 2016: 
 * - Texture.hpp created
 */
#ifndef VDK_TEXTURE_HPP_
#define VDK_TEXTURE_HPP_

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

namespace vdk {

	/////////////////////////////////////////////////////////////////////////////
	/// @class Texture
	///
	/// @todo Brief Description
	///
	/// Detailed Description
	/////////////////////////////////////////////////////////////////////////////
	class Texture {

		//-------------------------------------------------------------------------
		// Public Member Types
		//-------------------------------------------------------------------------
	public:


		//-------------------------------------------------------------------------
		// Constructor / Destructor / Assignment
		//-------------------------------------------------------------------------
	public:

		///
		/// @brief Constructs a Texture from a given image filepath
		///
		/// @param image the path to the image to load
		///
		Texture( const char* image );

		///
		/// Destructs this instance of Texure
		///
		~Texture();

		//-------------------------------------------------------------------------
		// Accessors
		//-------------------------------------------------------------------------
	public:

		size_t width() const;

		size_t height() const;

		//-------------------------------------------------------------------------
		// Private Members
		//-------------------------------------------------------------------------
	private:

		// Graphical texture
		SDL_Texture* m_texture; ///< The hardware image

		// dimensions
		size_t m_width;  ///< Width of the image
		size_t m_height; ///< Height of the image
	};


}  // namespace vdk



#endif /* VDK_TEXTURE_HPP_ */
