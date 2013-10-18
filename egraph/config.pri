CONFIG          += console
CONFIG          += c++11
CONFIG          -= app_bundle
CONFIG          -= qt

QT              -= core gui

QMAKE_CXX       = clang++
QMAKE_CXXFLAGS  = -Werror -Wall
