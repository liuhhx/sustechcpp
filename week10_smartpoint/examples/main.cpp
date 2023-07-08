#include "time.hpp"
#include <memory>
#include <iostream>
#pragma once

std::shared_ptr<MyTime> mt1(new MyTime(10));

std::shared_ptr<MyTime> mt2 = mt1;

auto mt3 = std::make_shared<MyTime>(1, 40);


std::unique_ptr<MyTime> umt1(new MyTime(10));

std::unique_ptr<MyTime> umt2 = std::make_unique<MyTime>(20,2); // c++17

std::unique_ptr<MyTime> umt3 = std::move(umt1); // 给另一个指针必须用move
