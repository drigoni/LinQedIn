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

#ifndef LINQEDINADMIN_H
#define LINQEDINADMIN_H

#include <db.h>
#include <auser.h>
#include <freeuser.h>

class LinQedInAdmin
{
private:
    DB* db;

public:
    LinQedInAdmin(DB*);
    virtual ~LinQedInAdmin();

    //metodi di ricerca utente nel database
    virtual AUser* FindUser(const QString&) const; //cerca un utente per email nel DB e restituisce un puntatore ad esso o 0
    virtual QVector<AUser*> FindUser(const QString&,const QString&,const QString&)const;//cerca un utente per nome,cognome ed email e restituisce un vettore  a utenti che combaciano

    //metodi per le operazioni sul database
    bool IsDBLoad()const;//Restituisce true se il database è caricato
    bool LoadDB(const QString&)const; //popola il DB di utenti di una precisa DBPath
    bool SaveDB()const;//salva il DB degli utenti in DBPath
    virtual bool SaveDB(const QString&)const; //salva il DB degli utenti in un preciso path
    bool CloseDB()const; //chiude il DB e lo pulisce
    bool RestartDB()const; //ricarica il DB

    //metodi di aggiunta utente con passaggio di nome,cognome,email,password
    void AddFreeUser(const QString&,const QString&,const QString&,const QString&)const;//aggiunge un utente Free
    void AddBusinessUser(const QString&,const QString&,const QString&,const QString&)const;//aggiunge un utente Business
    void AddExecutiveUser(const QString&,const QString&,const QString&,const QString&)const;//aggiunge un utente Executive


    bool RemoveUser(const QString&)const; //rimuove un utente dal database e ritorna true in caso di successo
    virtual void ChangeSubscriptionType(AUser*,const QString&)const;//cambia il subscription type dell'utente
};

#endif // LINQEDINADMIN_H
