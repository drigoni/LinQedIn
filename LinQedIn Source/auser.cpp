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

#include "auser.h"

AUser::AUser(const QString& name,const QString& surname,const QString& email,const QString& password)
    :Friends(new UserContactsNetwork()),Profile(new UserBaseInformations())
{
    //imposto i dati dell'utente
    Profile->SetName(name);
    Profile->SetSurname(surname);
    Profile->SetEmail(email);
    this->SetEncryptedPassword(password);
}

AUser::AUser(const QString &pass, UserContactsNetwork* contacts, UserBaseInformations * prof)
    :encryptedPassword(pass),Friends(contacts),Profile(prof)
{}

AUser::~AUser()
{
    //elimino dallo heap
    delete Friends;
    delete Profile;
}


//---------------------------------
//------------METODI----------------
//----------------------------------
QString AUser::GetEncryptedPassword()const
{
    //ritorno la password criptata
    return this->encryptedPassword;
}

void AUser::SetEncryptedPassword(const QString& Password)
{
    //cripto la password e la salvo
    this->encryptedPassword = this->DoEncryptedPassword(Password);
}

QString AUser::DoEncryptedPassword(const QString& password)
{
    //esempio di criptazione
    QString final = QString(QCryptographicHash::hash(password.toStdString().c_str(),QCryptographicHash::Md5).toHex());
    return final;
}



