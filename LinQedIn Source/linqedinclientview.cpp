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

#include "linqedinclientview.h"

LinQedInClientView::LinQedInClientView(UserBaseInfView* pUBIV, UserContactsNetView* pUCNV ,UsersSearchView* pUS)
    :BaseInfTab(pUBIV),NetworkTab(pUCNV),SearchTab(pUS)
{
    this->initView();
}

LinQedInClientView::~LinQedInClientView()
{}


//---------------------------------
//------------METODI----------------
//----------------------------------
void LinQedInClientView::initView()
{
    //allocamento dei campi dati nello heap
    tabWidget = new QTabWidget(this);
    thisLayout = new QVBoxLayout();

    //config tabWidget
    tabWidget->addTab(BaseInfTab,"Informazioni");
    tabWidget->addTab(NetworkTab,"Amici");
    tabWidget->addTab(SearchTab,"Cerca");

    //config thisLayout
    thisLayout->addWidget(tabWidget);

    //config this
    this->setWindowTitle(tr("LinQedInClient"));
    this->setLayout(thisLayout);
    this->setMinimumSize(850,650);

    //CONNECT
    //config TAB BaseInformation
    connect(BaseInfTab,SIGNAL(SaveBtnClicked(UserBaseInformations*)),this,SIGNAL(BaseInfChanged(UserBaseInformations*)));
    connect(BaseInfTab,SIGNAL(BaseInfAsked()),this,SIGNAL(BaseInfAsked()));

    //config TAB Network
    connect(NetworkTab,SIGNAL(RemoveFriendClicked(QString)),this,SIGNAL(FriendRemoved(QString)));
    connect(NetworkTab,SIGNAL(FriendsNetworkAsked()),this,SIGNAL(FriendsNetworkAsked()));

    //config SearchTab
    connect(SearchTab,SIGNAL(UserFormAsked()),this,SIGNAL(UserFormAsked()));
    connect(SearchTab,SIGNAL(Search(UserBaseInformations*)),this,SIGNAL(Search(UserBaseInformations*)));
    connect(SearchTab,SIGNAL(AddFriend(QString)),this,SIGNAL(FriendAdded(QString)));

    connect(NetworkTab,SIGNAL(ViewProfile(QString)),this,SIGNAL(ViewProfile(QString)));
    connect(SearchTab,SIGNAL(ViewProfile(QString)),this,SIGNAL(ViewProfile(QString)));
}

void LinQedInClientView::ShowBaseInf(const UserBaseInformations *p) const
{
    this->BaseInfTab->ShowBaseInf(p);
}


void LinQedInClientView::ShowAllFriendsNetwork(const QList<const UserBaseInformations*> p)const
{
    this->NetworkTab->ShowAllFriendsNetwork(p);
}

void LinQedInClientView::SetUserForm(const QString & s)const
{
    this->SearchTab->SetUserForm(s);
}

void LinQedInClientView::ShowSearchResult(const QList<const UserBaseInformations*> &l) const
{
    this->SearchTab->ShowSearchResult(l);
}

