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

#ifndef AUSER_H
#define AUSER_H

#include<QString>
#include<QList>
#include<QCryptographicHash>
#include<QMap>

#include<userbaseinformations.h>
#include<usercontactsnetwork.h>

class AUser
{
private:
    QString encryptedPassword;//campo dati contenente la password Cryptata

public:
    AUser(const QString&,const QString&,const QString&,const QString&); //crea l'utente avente Nome,Cognome,Email,Password
    AUser(const QString&,UserContactsNetwork*,UserBaseInformations*); //crea l'utente passando Email,ReteAmicizie,Profilo
    virtual ~AUser(); //distruttore

    //campi membro
    UserContactsNetwork* Friends;//Amici dell'utente
    UserBaseInformations* Profile;//Profilo utente

    //metodi
    QString GetEncryptedPassword()const; //Ottiene la password cryptata dell'utente
    virtual void SetEncryptedPassword(const QString&); //Setta la password cryptata avente quella in chiaro
    virtual QString GetSubscriptionType()const = 0; //ottiene il tipo dell'utente
    virtual QString DoEncryptedPassword(const QString&); //Funzione per criptare le password

    //Funzione di ricerca dato l'iteratore di inizio, quello di fine,e le informazioni
    QList<const UserBaseInformations*> virtual Search(QMap<QString,AUser*>::const_iterator,QMap<QString,AUser*>::const_iterator,const UserBaseInformations&)const=0;

};

#endif // AUSER_H
