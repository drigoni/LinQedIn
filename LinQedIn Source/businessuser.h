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

#ifndef BUSINESSUSER_H
#define BUSINESSUSER_H

#include <auser.h>
#include <QSet>

class BusinessUser:public AUser
{
public:
    BusinessUser(const QString&,const QString&,const QString&,const QString&); //crea l'utente avente Nome,Cognome,Email,Password
    BusinessUser(const QString&, UserContactsNetwork*,UserBaseInformations*); //crea l'utente passando Email,ReteAmicizie,Profilo

    //metodi
    virtual QString GetSubscriptionType()const;//ottiene il tipo dell'utente

    //Funzione di ricerca dato l'iteratore di inizio, quello di fine,e le informazioni
    QList<const UserBaseInformations*> virtual Search(QMap<QString,AUser*>::const_iterator,QMap<QString,AUser*>::const_iterator,const UserBaseInformations&)const;
};

#endif // BUSINESSUSER_H
