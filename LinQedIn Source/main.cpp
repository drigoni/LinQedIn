/*
    This software was inspired by Linkedin as desired to simulate a service 
    where registered users can join together through a network of friends.
	The purpose of this project is to create software that exploits as much as possible 
	the concept of polymorphism and inheritance using the MVC design pattern.
    Copyright (C) 2016  Davide Rigoni

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include <QApplication>
#include <linqedinlogincontroller.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //configuro a in modo che si chiuda solo quando non ci saranno più finestre aperte
    a.setQuitOnLastWindowClosed(true);

    LinQedInLoginController* app = new LinQedInLoginController();
    app->Show();

    return a.exec();
}
