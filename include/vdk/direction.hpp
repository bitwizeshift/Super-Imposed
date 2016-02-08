/**
 * @file direction.hpp
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
 * - direction.hpp created
 */
#ifndef VDK_DIRECTION_HPP_
#define VDK_DIRECTION_HPP_

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

#include "types.hpp"

namespace vdk{

	///
	/// @enum vdk::direction
	///
	/// A safe enumeration of accessibility flags that are operable
	///
	enum class direction : ubyte{
		none   = 0x00, ///< No face
		top    = 0x01, ///< Top-Facing
		right  = 0x02, ///< Right-Facing
		bottom = 0x04, ///< Bottom-Facing
		left   = 0x08, ///< Left-Facing
		all    = 0x0f  ///< All directions (for collisions)
	};

}

#endif /* VDK_DIRECTION_HPP_ */
