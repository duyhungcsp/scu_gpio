/*
Copyright (c) 2012-2017 Ben Croston ben@croston.org.
Copyright (c) 2019, NVIDIA CORPORATION.
Copyright (c) 2019 Jueon Park(pjueon) bluegbg@gmail.com.
Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#include <iostream>
#include "JetsonGPIO.h"

using namespace std;

int main()
{
	cout << "model: "<< GPIO::model << endl;
	cout << "lib version: " << GPIO::VERSION << endl;
	cout << GPIO::JETSON_INFO << endl;


	int output_pin = 29;
	GPIO::setmode(GPIO::BOARD);
	GPIO::setup(output_pin, GPIO::OUT, GPIO::LOW);
	


	cout << "BOARD "<< output_pin << "pin, set to OUTPUT, HIGH" << endl;
	GPIO::output(output_pin, GPIO::HIGH);
    cout << "Press Enter to Continue";
	cin.ignore();

	cout << output_pin <<"pin, set to LOW now" << endl;
	GPIO::output(output_pin, GPIO::LOW);
	cout << "Press Enter to Continue";
	cin.ignore();

	GPIO::cleanup();	

	cout << "end" << endl;	
	return 0;
}
