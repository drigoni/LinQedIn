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

#include "usercontactsnetwork.h"


UserContactsNetwork::~UserContactsNetwork()
{}

//---------------------------------
//------------METODI----------------
//----------------------------------
bool UserContactsNetwork::Add(const QString& u)
{
    if(this->network.contains(u))
    {
        //ritorno false
        return false;
    }
    else
    {
        //aggiungo
        this->network.push_back(u);
        return true;
    }
}

bool UserContactsNetwork::Remove(const QString& u)
{
    //trovo l'indice dell'elemeno da eliminare
    int index = this->network.indexOf(u);
    //verifico il risultato
    if(index != -1)
    {
        //rimuovo dalla lista degli utenti
        network.removeAt(index);
        return true;
    }
    else
        return false;
}

int UserContactsNetwork::GetSize()const
{
    return this->network.size();
}

QList<QString>::const_iterator UserContactsNetwork::Begin()const
{
    return network.constBegin();
}

QList<QString>::const_iterator UserContactsNetwork::End()const
{
    return network.constEnd();
}


