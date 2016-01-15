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

#ifndef LINQEDINCLIENTCONTROLLER_H
#define LINQEDINCLIENTCONTROLLER_H

#include <linqedinclient.h>
#include <linqedinclientview.h>

class LinQedInClientController:public QObject
{
    Q_OBJECT
private:
    LinQedInClient *model;
    LinQedInClientView *view;

protected:
    virtual void initController();//inizzializza il controllore

public:
    LinQedInClientController(LinQedInClient*,LinQedInClientView*);//costruttore che necessita di un puntatore al client e alla view
    virtual ~LinQedInClientController();//distruttore

    void Show()const;//visualizza la view

public slots:
    //view BaseInfTab
    void BaseInfAsk();//riceve il segnale di richiesta del profilo dell'utente
    void BaseInfChange(UserBaseInformations*);//salva il profilo aggiornato
    //view NetworkTab
    void FriendRemove(QString);//rimuove un amico utilizzando l'email come parametro
    void FriendsNetworkAsk();//visualizza tutta la rete delle amicizie
    //View SearchTab
    void UserFormAsk();//setta la form della view in base al tipo dell'utente
    void Search(UserBaseInformations*);//cerca un utente che combaci con il profilo passato come parametro
    void FriendAdd(QString);//aggiung un amico alla lista delle amicizie

    //NetworkTab && SearchTab
    void ViewProfile(QString);//visualizza un profilo di un utente avente come parametro l'email

};

#endif // LINQEDINCLIENTCONTROLLER_H
