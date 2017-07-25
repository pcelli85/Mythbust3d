/**
 * MythBust3d 3D Printer Firmware
 *
 * Based on OpenSource Firmware, modified in some part from (Domenico Ponticelli) Pcelli85
 * MythBust3d Beta Testing Version modded on 26-01-2017
 * Able to run over the ANET V1.0 Original Controller of ANET A8
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * Copyright (c) 2013 Arduino LLC. All right reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * Defines for 16 bit timers used with Servo library
 *
 * If _useTimerX is defined then TimerX is a 16 bit timer on the current board
 * timer16_Sequence_t enumerates the sequence that the timers should be allocated
 * _Nbr_16timers indicates how many 16 bit timers are available.
 */

#ifdef ARDUINO_ARCH_SAM
  /**
   * SAM Only definitions
   * --------------------
   */

  // For SAM3X:
  //#define _useTimer1
  //#define _useTimer2
  #define _useTimer3
  //#define _useTimer4
  #define _useTimer5

  /*
    TC0, chan 0 => TC0_Handler
    TC0, chan 1 => TC1_Handler
    TC0, chan 2 => TC2_Handler
    TC1, chan 0 => TC3_Handler
    TC1, chan 1 => TC4_Handler
    TC1, chan 2 => TC5_Handler
    TC2, chan 0 => TC6_Handler
    TC2, chan 1 => TC7_Handler
    TC2, chan 2 => TC8_Handler
   */

  #if defined (_useTimer1)
    #define TC_FOR_TIMER1       TC1
    #define CHANNEL_FOR_TIMER1  0
    #define ID_TC_FOR_TIMER1    ID_TC3
    #define IRQn_FOR_TIMER1     TC3_IRQn
    #define HANDLER_FOR_TIMER1  TC3_Handler
  #endif
  #if defined (_useTimer2)
    #define TC_FOR_TIMER2       TC1
    #define CHANNEL_FOR_TIMER2  1
    #define ID_TC_FOR_TIMER2    ID_TC4
    #define IRQn_FOR_TIMER2     TC4_IRQn
    #define HANDLER_FOR_TIMER2  TC4_Handler
  #endif
  #if defined (_useTimer3)
    #define TC_FOR_TIMER3       TC1
    #define CHANNEL_FOR_TIMER3  2
    #define ID_TC_FOR_TIMER3    ID_TC5
    #define IRQn_FOR_TIMER3     TC5_IRQn
    #define HANDLER_FOR_TIMER3  TC5_Handler
  #endif
  #if defined (_useTimer4)
    #define TC_FOR_TIMER4       TC0
    #define CHANNEL_FOR_TIMER4  2
    #define ID_TC_FOR_TIMER4    ID_TC2
    #define IRQn_FOR_TIMER4     TC2_IRQn
    #define HANDLER_FOR_TIMER4  TC2_Handler
  #endif
  #if defined (_useTimer5)
    #define TC_FOR_TIMER5       TC0
    #define CHANNEL_FOR_TIMER5  0
    #define ID_TC_FOR_TIMER5    ID_TC0
    #define IRQn_FOR_TIMER5     TC0_IRQn
    #define HANDLER_FOR_TIMER5  TC0_Handler
  #endif

  typedef enum { _timer3, _timer5, _Nbr_16timers } timer16_Sequence_t ;

  #define TRIM_DURATION          2 // compensation ticks to trim adjust for digitalWrite delays
  #define SERVO_TIMER_PRESCALER 32 // timer prescaler

#else // !ARDUINO_ARCH_SAM

  /**
   * AVR Only definitions
   * --------------------
   */

  // Say which 16 bit timers can be used and in what order
  #if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
    #define _useTimer5
    #define _useTimer3
    #define _useTimer4
    typedef enum { _timer5, _timer3, _timer4, _Nbr_16timers } timer16_Sequence_t;

  #elif defined(__AVR_ATmega32U4__)
    #define _useTimer3
    typedef enum { _timer3, _Nbr_16timers } timer16_Sequence_t;

  #elif defined(__AVR_AT90USB646__) || defined(__AVR_AT90USB1286__)
    #define _useTimer3
    typedef enum { _timer3, _Nbr_16timers } timer16_Sequence_t;

  #elif defined(__AVR_ATmega128__) ||defined(__AVR_ATmega1281__)||defined(__AVR_ATmega2561__)
    #define _useTimer3
    typedef enum { _timer3, _Nbr_16timers } timer16_Sequence_t;

  #else  // everything else
    typedef enum { _Nbr_16timers } timer16_Sequence_t;
  #endif

  #define TRIM_DURATION         2 // compensation ticks to trim adjust for digitalWrite delays
  #define SERVO_TIMER_PRESCALER 8 // timer prescaler

#endif
