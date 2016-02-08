/**
 * @file Timer.hpp
 *
 * @todo Add description
 *
 * @author Matthew Rodusek (matthew.rodusek@gmail.com)
 * @date   Jan 23, 2016
 *
 */

/*
 * Change Log:
 *
 * Jan 23, 2016: 
 * - Timer.hpp created
 */
#ifndef VDK_TIMER_HPP_
#define VDK_TIMER_HPP_

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

namespace vdk{

	////////////////////////////////////////////////////////////////////////////
	/// @class vdk::Timer
	///
	/// @brief A Timer utility class for determining the passage of time.
	///
	/// This is necessary for detecting frame-skips, or for frame-locking
	////////////////////////////////////////////////////////////////////////////
	class Timer{

		//------------------------------------------------------------------------
		// Constructor / Destructor
		//------------------------------------------------------------------------
	public:

		///
		/// @brief Constructs an instance of this Timer
		///
		Timer();

		//------------------------------------------------------------------------
		// Timer APi
		//------------------------------------------------------------------------
	public:

		//The various clock actions
		///
		/// @brief Starts the clock timing
		///
		void start();

		///
		/// @brief Stops the clock timing
		///
		void stop();

		///
		/// @brief Pauses the clock timing
		///
		void pause();

		///
		/// @brief Unpauses the clock timing
		///
		void unpause();

		///
		/// Gets the number of ticks passed
		///
		/// @return the number of ticks
		///
		int get_ticks();

		///
		/// Checks if the status of the Timer to see if it has started
		///
		/// @return @c true if Timer is started
		///
		bool is_started();

		///
		/// Checks if the status of the Timer to see if it is paused
		///
		/// @return @c true if Timer is paused
		///
		bool is_paused();

		//------------------------------------------------------------------------
		// Private Members
		//------------------------------------------------------------------------
	private:

		//The clock time when the timer started
		int m_start_ticks;

		//The ticks stored when the timer was paused
		int m_paused_ticks;

		//The timer status
		bool m_is_paused;
		bool m_is_started;

	};
}

#endif /* VDK_TIMER_HPP_ */
