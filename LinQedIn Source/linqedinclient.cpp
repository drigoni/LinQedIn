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

#include "linqedinclient.h"

LinQedInClient::LinQedInClient(DB* pdb,AUser* puser):db(pdb),user(puser)
{
}

LinQedInClient::~LinQedInClient()
{}


//---------------------------------
//------------METODI----------------
//----------------------------------
const AUser* LinQedInClient::FindUser(const QString& email) const
{
    return db->FindUser(email);
}

void LinQedInClient::SaveNewInformation(UserBaseInformations* p)const
{
    delete this->user->Profile;
    this->user->Profile = p;
    this->db->Save();
}

bool LinQedInClient::AddFriend(const QString& email) const
{
    user->Friends->Add(email);
    return this->db->Save();
}

bool LinQedInClient::RemoveFriend(const QString& email) const
{
    user->Friends->Remove(email);
    return this->db->Save();
}

const UserBaseInformations* LinQedInClient::GetProfile()const
{
    return user->Profile;
}

const UserContactsNetwork* LinQedInClient::GetFriends()const
{
    return user->Friends;
}

const QList<const UserBaseInformations*> LinQedInClient::GetAllFriendsData()const
{
    QList<const UserBaseInformations*> p;
    for(QList<QString>::const_iterator it = user->Friends->Begin();it!=user->Friends->End();++it)
    {
        QString temp = *it;
        const AUser* a  = this->FindUser(*it);
        p.push_back(a->Profile);
    }
    return p;
}

QString LinQedInClient::GetUserForm()const
{
    if(dynamic_cast<ExecutiveUser*>(user))
        return "ExecutiveUser";
    else if(dynamic_cast<BusinessUser*>(user))
        return "BusinessUser";
    else if(dynamic_cast<FreeUser*>(user))
        return "FreeUser";
}

QList<const UserBaseInformations*> LinQedInClient::Search(UserBaseInformations* inf)const
{
    QList<const UserBaseInformations*> temp = this->user->Search(db->ConstBegin(),db->ConstEnd(),*inf);
    delete inf;
    return temp;
}

UserBaseInformations* LinQedInClient::GetUserProfile(const QString & email) const
{
    return (this->db->FindUser(email))->Profile;
}



