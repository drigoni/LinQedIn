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

#include "linqedinclientcontroller.h"


LinQedInClientController::LinQedInClientController(LinQedInClient* pm,LinQedInClientView* pv)
    :model(pm), view(pv)
{
    this->initController();
}

LinQedInClientController::~LinQedInClientController()
{}


//---------------------------------
//------------METODI----------------
//----------------------------------
void LinQedInClientController::initController()
{
    //connect
    connect(this->view,SIGNAL(BaseInfAsked()),this,SLOT(BaseInfAsk()));
    connect(this->view,SIGNAL(BaseInfChanged(UserBaseInformations*)),this,SLOT(BaseInfChange(UserBaseInformations*)));
    //richiamo il metodo nella view per l'inserimento dei dati base
    this->view->ShowBaseInf(this->model->GetProfile());

    connect(this->view,SIGNAL(FriendRemoved(QString)),this,SLOT(FriendRemove(QString)));
    connect(this->view,SIGNAL(FriendsNetworkAsked()),this,SLOT(FriendsNetworkAsk()));
    //richiamo il metodo nella view per l'inserimento dei dati
    this->view->ShowAllFriendsNetwork(this->model->GetAllFriendsData());

    connect(this->view,SIGNAL(UserFormAsked()),this,SLOT(UserFormAsk()));
    connect(this->view,SIGNAL(Search(UserBaseInformations*)),SLOT(Search(UserBaseInformations*)));
    //richiamo il metodo nella view per il settaggio della form di ricerca
    this->view->SetUserForm(this->model->GetUserForm());
    connect(this->view,SIGNAL(FriendAdded(QString)),this,SLOT(FriendAdd(QString)));

    connect(this->view,SIGNAL(ViewProfile(QString)),this,SLOT(ViewProfile(QString)));
}

void LinQedInClientController::Show()const
{
    this->view->show();
}

//slots
void LinQedInClientController::BaseInfAsk()
{
    //richiamo il metodo nella view per l'inserimento
    this->view->ShowBaseInf(this->model->GetProfile());
}

void LinQedInClientController::BaseInfChange(UserBaseInformations* p)
{
    this->model->SaveNewInformation(p);
}

void LinQedInClientController::FriendsNetworkAsk()
{
    //mando la rete delle amicizie alla view
    this->view->ShowAllFriendsNetwork(this->model->GetAllFriendsData());
}

void LinQedInClientController::FriendRemove(QString email)
{
    //rimozione amico
    this->model->RemoveFriend(email);
}

void LinQedInClientController::UserFormAsk()
{
    this->view->SetUserForm(this->model->GetUserForm());
}

void LinQedInClientController::Search(UserBaseInformations* inf)
{
    this->view->ShowSearchResult(this->model->Search(inf));
}

void LinQedInClientController::FriendAdd(QString email)
{
    //aggiunta amico
    this->model->AddFriend(email);
}

void LinQedInClientController::ViewProfile(QString email)
{
   //creo una nuova form
    UserBaseInfView* profileView= new UserBaseInfView(this->model->GetUserProfile(email));
    profileView->show();
}
