/**
 * @file Tile.hpp
 *
 * @todo Add description
 *
 * @author Matthew Rodusek (matthew.rodusek@gmail.com)
 * @date   Feb 7, 2016
 *
 */

/*
 * Change Log:
 *
 * Feb 7, 2016: 
 * - Tile.hpp created
 */
#ifndef VDK_TILE_HPP_
#define VDK_TILE_HPP_

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

#include "direction.hpp"

namespace vdk {

	/////////////////////////////////////////////////////////////////////////////
	/// @class Tile
	///
	/// @todo Brief Description
	///
	/// Detailed Description
	/////////////////////////////////////////////////////////////////////////////
	template<
		size_t width  = 32,
		size_t height = 32
	>
	class Tile {

		//-------------------------------------------------------------------------
		// Public Member Types
		//-------------------------------------------------------------------------
	public:

		typedef size_t id_type; ///< Type representing a tile ID

		//-------------------------------------------------------------------------
		// Constructor / Destructor / Assignment
		//-------------------------------------------------------------------------
	public:

		///
		/// Constructs a Tile given the location
		///
		/// @param id The id for this tile
		/// @param x  The x position of this tile in the source image
		/// @param y  The y position of this tile in the source image
		/// @param access the accessibility of this tile
		/// @param flags additional information stored in bit flags
		///
		Tile( id_type id, size_t x, size_t y, ubyte access, ubyte flags = 0 );

		//-------------------------------------------------------------------------
		// Accessors
		//-------------------------------------------------------------------------
	public:

		///
		/// @brief Gets the tile id of this tile
		///
		/// @return the tile id
		///
		id_type tile_id() const;

		///
		/// @brief Gets the bounding box for this tile
		///
		/// @return the tile boundary
		///
		SDL_Rect tile_boundary() const;

		//-------------------------------------------------------------------------
		// Passability
		//-------------------------------------------------------------------------
	public:

		///
		/// @brief Checks whether this tile is passable in the specified direction
		///
		/// @param dir the direction to check is passable
		/// @return @c true if the tile can be passed from that direction
		///
		bool is_passable( direction dir ) const;

		///
		/// @brief Checks if this tile is passable in any direction
		///
		/// @return @c true if the tile can be passed in any direction
		///
		bool any_passable() const;

		///
		/// @brief Checks whether this tile is passable from the top
		///
		/// @return @c true if the tile can be passed from the top
		///
		bool top_passable() const;

		///
		/// @brief Checks whether this tile is passable from the right
		///
		/// @return @c true if the tile can be passed from the right
		///
		bool right_passable() const;

		///
		/// @brief Checks whether this tile is passable from the bottom
		///
		/// @return @c true if the tile can be passed from the bottom
		///
		bool bottom_passable() const;

		///
		/// @brief Checks whether this tile is passable from the left
		///
		/// @return @c true if the tile can be passed from the left
		///
		bool left_passable() const;

		//-------------------------------------------------------------------------
		// Private Members
		//-------------------------------------------------------------------------
	private:

		id_type  m_id;          ///< The id of this tile
		SDL_Rect m_boundary;    ///< The bounding box of this tile
		ubyte    m_flags;       ///< The individual flags for this tile
		ubyte    m_passability; ///< The passability values of this tile

	};

	//--------------------------------------------------------------------------
	// Inline Constructor Definition
	//--------------------------------------------------------------------------

	template<size_t w, size_t h>
	inline Tile<w,h>::Tile( id_type id, size_t x, size_t y, ubyte access, ubyte flags )
		: m_id(id),
			m_boundary{ x, y, w, h },
			m_flags(flags),
			m_passability(access)
	{

	}

	//--------------------------------------------------------------------------
	// Inline Accessor Definitions
	//--------------------------------------------------------------------------

	template<size_t w, size_t h>
	inline Tile<w,h>::id_type Tile<w,h>::tile_id() const{
		return m_id;
	}

	template<size_t w, size_t h>
	inline SDL_Rect Tile<w,h>::tile_boundary() const{
		return m_boundary;
	}

	//--------------------------------------------------------------------------
	// Inline Passability definitions
	//--------------------------------------------------------------------------

	template<size_t w, size_t h>
	inline bool Tile<w,h>::is_passable( direction dir ) const{
		return (m_passability & dir) == dir;
	}

	template<size_t w, size_t h>
	inline bool Tile<w,h>::any_passable() const{
		return (m_passability & direction::all) == direction::all;
	}

	template<size_t w, size_t h>
	inline bool Tile<w,h>::top_passable() const{
		return m_passability & direction::top;
	}

	template<size_t w, size_t h>
	inline bool Tile<w,h>::left_passable() const{
		return m_passability & direction::left;
	}

	template<size_t w, size_t h>
	inline bool Tile<w,h>::bottom_passable() const{
		return m_passability & direction::bottom;
	}

	template<size_t w, size_t h>
	inline bool Tile<w,h>::left_passable() const{
		return m_passability & direction::left;
	}

}  // namespace vdk



#endif /* VDK_TILE_HPP_ */
