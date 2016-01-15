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

#ifndef LINQEDINCLIENT_H
#define LINQEDINCLIENT_H

#include <auser.h>
#include <db.h>

class LinQedInClient
{
private:
    DB* db;
    AUser* user;

public:
    LinQedInClient(DB*,AUser*);//costruttore che necessita di puntatore al db e puntatore all'utente
    virtual ~LinQedInClient();

    //metodi
    virtual const AUser* FindUser(const QString&) const; //cerca un utente per email nel DB e restituisce un puntatore ad esso o 0
    virtual void SaveNewInformation(UserBaseInformations*)const;//salva il nuovo profilo passato all'utente ed elimina il precedente
    virtual bool AddFriend(const QString&)const;//aggiunge un nuovo amico nella rete delle amicizie
    virtual bool RemoveFriend(const QString&)const;//rimuove un amico presente nella rete delle amicizie
    virtual QString GetUserForm()const;//ritorna il tipo di form necessaria per la ricerca
    virtual QList<const UserBaseInformations*> Search(UserBaseInformations*)const;//cerca gli utenti nel db che combaciano con i dati passati
    UserBaseInformations* GetUserProfile(const QString&)const;//ritorna il profilo di un utente

    const UserBaseInformations* GetProfile()const;//ritorna il profilo dell'utente loggato
    const UserContactsNetwork* GetFriends()const;//ritorna la rete delle amicizie dell'utente loggato
    const QList<const UserBaseInformations*> GetAllFriendsData()const;//ritorna tutti profili degli amici dell'utente loggato
};

#endif // LINQEDINCLIENT_H
