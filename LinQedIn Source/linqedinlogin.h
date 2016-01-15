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

#ifndef LINQEDINLOGIN_H
#define LINQEDINLOGIN_H

#include <db.h>
#include <linqedinadmincontroller.h>
#include <linqedinclientcontroller.h>

class LinQedInLogin
{
protected:
    //metodo di ricerca
    virtual AUser* FindUser(DB*,const QString&,const QString&) const; //cerca un utente per email e password nel DB e restituisce un puntatore ad esso o 0

public:
    LinQedInLogin();
    virtual ~LinQedInLogin();//distruttore

    //metodi
    virtual bool DoAdminLogin()const; //verifica se un admin si sta connettendo.
                                                                   //Ritorna true e apre il client o false
    virtual bool DoClientLogin(const QString&,const QString&)const; //verifica se un client si sta connettendo.
                                                                    //Ritorna true e apre il client o false
};

#endif // LINQEDINLOGIN_H
