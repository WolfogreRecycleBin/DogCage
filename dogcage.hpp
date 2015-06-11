/******************************************************************************
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2015-15 Jason Song <wolfogrea@qq.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 ******************************************************************************/
#pragma once

#include <iostream>
#include <thread>

int _main();
namespace dogcage
{
	bool dog_is_in_cage = true;
	int return_value = 0;
	void Dog()
	{
		return_value = _main();
		dog_is_in_cage = false;
	}
}
int main()
{
	std::thread t(dogcage::Dog);
	t.detach();
	std::cout << "--------------------------------------Dog ran into the cage!---------------------------------------" << std::endl;
	int used_time = 0;
	while(dogcage::dog_is_in_cage && used_time <= 5)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		used_time += 1;
	}
	if(dogcage::dog_is_in_cage)
	{
		std::cout << "--------------------------------------Dog has been killed!--------------------------------------" << std::endl;
		std::cout << "--------------------------------------Dog has been killed!--------------------------------------" << std::endl;
		std::cout << "--------------------------------------Dog has been killed!--------------------------------------" << std::endl;
		std::cout << "--------------------------------------Dog has been killed!--------------------------------------" << std::endl;
		std::cout << "--------------------------------------Dog has been killed!--------------------------------------" << std::endl;
		std::cout << "--------------------------------------Dog has been killed!--------------------------------------" << std::endl;
		std::cout << "--------------------------------------Dog has been killed!--------------------------------------" << std::endl;
		std::cout << "--------------------------------------Dog has been killed!--------------------------------------" << std::endl;
	}
	else
	{
		std::cout << "--------------------------------------Dog ran out of the cage!Return " << dogcage::return_value<< "--------------------------------------" << std::endl;
	}
	return dogcage::return_value;
}

#ifndef main
#define main _main
#endif
