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

#ifndef DB_H
#define DB_H

#include <QMap>
#include <QVector>
#include <QSet>

#include <auser.h>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QFile>
#include <freeuser.h>
#include <businessuser.h>
#include <executiveuser.h>


class DB
{
protected:
    QMap<QString,AUser*> users; //contenitore di puntatori ad utenti allocati nello heap
    QString DBPath; //path del file .xml

    virtual void clearDB();//metodo che svuota il db
public:
    DB(const QString&);//crea DB ed effettua il Load
    virtual ~DB();//distruttore

    //iteratori
    QMap<QString,AUser*>::iterator Begin();
    QMap<QString,AUser*>::iterator End();
    //iteratori costanti
    QMap<QString,AUser*>::const_iterator ConstBegin()const;
    QMap<QString,AUser*>::const_iterator ConstEnd()const;


    //metodi del database
    bool IsLoad()const;//verifica se il db è caricato
    virtual bool Load(const QString&); //popola il database di utenti presenti in un file .xml. True->Successo, False->DB già inizializzato
    bool Save()const;//salva il database degli utenti in DBPath. True->Successo, False->DB non inizializzato
    virtual bool Save(const QString&)const; //salva il database degli utenti in un file .xml. True->Successo, False->DB non inizializzato
    virtual bool Close(); //svuota il database. True->DB chiuso, False->DB non inizializzato
    bool Restart(); //chiudo e riapro il DB presente in DBPath. True->Successo, False->DB non inizializzato

    virtual void AddUser(AUser*); //aggiunge un utente al DB
    virtual bool RemoveUser(AUser*);//rimuove un utente dal DB e ritorna true in caso di successo
    virtual AUser* FindUser(const QString&) const; //cerca un utente per chiave nel DB e restituisce un puntatore ad esso o 0
};

#endif // DB_H
