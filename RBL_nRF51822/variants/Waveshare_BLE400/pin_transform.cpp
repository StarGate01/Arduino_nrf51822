/*
    Copyright (c) 2014 RedBearLab, All rights reserved.

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    See the GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
    CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
    TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
    SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include "Arduino.h"
#include "pin_transform.h"


/**********************************************************************
name :
function : 
**********************************************************************/
PinName Pin_nRF51822_to_Arduino(uint32_t pin)
{
	PinName return_pin = (PinName)NC;
	
	switch(pin)
	{	
		case 0 : return_pin = P0_0;break;//
		case 1 : return_pin = P0_1;break;//
		case 2 : return_pin = P0_2;break;//
		case 3 : return_pin = P0_3;break;//
		case 4 : return_pin = P0_4;break;//
		case 5 : return_pin = P0_5;break;//
		case 6 : return_pin = P0_6;break;//
		case 7 : return_pin = P0_7;break;//
	
		case 8 : return_pin = P0_8;break;//
		case 9 : return_pin = P0_9;break;//
		case 10 : return_pin = P0_10;break;//
		case 11 : return_pin = P0_11;break;//
		case 12 : return_pin = P0_12;break;//
		case 13 : return_pin = P0_13;break;//
		
		case 14 : return_pin = P0_14;break;//
		case 15 : return_pin = P0_15;break;//
		
		case 16 : return_pin = P0_16;break;//
		case 17 : return_pin = P0_17;break;//
		case 18 : return_pin = P0_18;break;//
		
		case 19 : return_pin = P0_19;break;//
		case 20 : return_pin = P0_20;break;//
		case 21 : return_pin = P0_21;break;//
		case 22 : return_pin = P0_22;break;//
		case 23 : return_pin = P0_23;break;//
		case 24 : return_pin = P0_24;break;//

		case 25 : return_pin = P0_25;break;//
		case 26 : return_pin = P0_26;break;//		
		case 27 : return_pin = P0_27;break;//
		case 28 : return_pin = P0_28;break;//
		case 29 : return_pin = P0_29;break;//
		case 30 : return_pin = P0_30;break;//
//		case 31 : return_pin = P0_31;break;//		
		
		default : return_pin = (PinName)NC;break;		
	}
	return (return_pin);
}




















