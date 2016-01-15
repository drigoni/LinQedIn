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

#ifndef LINQEDINADMINCONTROLLER_H
#define LINQEDINADMINCONTROLLER_H

#include <linqedinadmin.h>
#include <linqedinadminview.h>

class LinQedInAdminController:public QObject
{
    Q_OBJECT
private:
    LinQedInAdmin *model;
    LinQedInAdminView *view;

protected:
    virtual void initController()const;//inizializzatore del controller

public:
    LinQedInAdminController(LinQedInAdmin*);//puntatore alla model come parametro e view creata automaticamente
    LinQedInAdminController(LinQedInAdmin*,LinQedInAdminView*);//puntatore al model e alla view come parametro
    virtual ~LinQedInAdminController();

    void Show()const;//visualizza la view

public slots:
    virtual void findUsers(const QString&,const QString&,const QString&);//trova un utente per nome,cognome,email
    virtual void addUser(const QString&,const QString&,const QString&,const QString&,const QString&,const QString&);//aggiunge un utente
    virtual void dbDoOperation(const QString&,const QString&);//esegue una operazione sul database. Parametri: operazione e path
    virtual void removeUser(const QString&);//rimuove un utente avendo come parametro l'indirizzo email
    virtual void changeSubscryptionType(const QString&,const QString&);//cambia tipo di iscrizione ad un utente avendo come parametri email e nuova iscrizione

};

#endif // LINQEDINADMINCONTROLLER_H
