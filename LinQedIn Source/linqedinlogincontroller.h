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

#ifndef LINQEDINLOGINCONTROLLER_H
#define LINQEDINLOGINCONTROLLER_H

#include <linqedinloginview.h>
#include <linqedinclientcontroller.h>
#include <linqedinlogin.h>
#include <db.h>


class LinQedInLoginController:public QObject
{
    Q_OBJECT
private:
    LinQedInLogin *model;
    LinQedInLoginView *view;

protected:
    virtual void initController()const;//inizzializza il controller

public:
    LinQedInLoginController();//costruttore di default
    LinQedInLoginController(LinQedInLogin*, LinQedInLoginView*);//costruttore con passaggiod dei puntatori
    virtual ~LinQedInLoginController();//distruttore

    //metodi
    void Show()const;//visualizza la view

public slots:
    virtual void doUserLogin(const QString&,const QString&);//esegue il login di un utente avente email e password
    virtual void doAdminLogin();//esegue il login dell'amministratore
};

#endif // LINQEDINLOGINCONTROLLER_H
