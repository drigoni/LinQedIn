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

#include "linqedinadmincontroller.h"

LinQedInAdminController::LinQedInAdminController(LinQedInAdmin* pm)
    :model(pm),view(new LinQedInAdminView())
{
    this->initController();
}

LinQedInAdminController::LinQedInAdminController(LinQedInAdmin* pm,LinQedInAdminView* pview)
    :model(pm),view(pview)
{
    this->initController();
}

LinQedInAdminController::~LinQedInAdminController()
{}


//------------------------------------------
//------------METODI PROTETTI----------------
//-------------------------------------------
void LinQedInAdminController::initController()const
{
    //connessioni dalla view al controller
    connect(this->view,SIGNAL(dbAddNewUser(QString,QString,QString,QString,QString,QString)),this,SLOT(addUser(QString,QString,QString,QString,QString,QString)));
    connect(this->view,SIGNAL(dbDoOperation(QString,QString)),this,SLOT(dbDoOperation(QString,QString)));
    connect(this->view,SIGNAL(dbRemoveUser(QString)),this,SLOT(removeUser(QString)));
    connect(this->view,SIGNAL(dbChangeUserSub(QString,QString)),this,SLOT(changeSubscryptionType(QString,QString)));
    connect(this->view,SIGNAL(dbFindUsers(QString,QString,QString)),this,SLOT(findUsers(QString,QString,QString)));
}


//---------------------------------
//------------METODI----------------
//----------------------------------
void LinQedInAdminController::Show()const
{
    this->view->show();
}

//slots
void LinQedInAdminController::findUsers(const QString& name, const QString& surname,const QString& email)
{
    QVector<AUser*> r = this->model->FindUser(name,surname,email);
    this->view->ShowUsersResult(r,this->model->IsDBLoad());
}

void LinQedInAdminController::addUser(const QString& n,const QString& s,const QString& e,const QString& p,const QString& cp,const QString& type)
{
    //se le password coincidono
    if(cp == p)
    {
        if(type == "FreeUser")
            this->model->AddFreeUser(n,s,e,p);
        else if(type == "BusinessUser")
            this->model->AddBusinessUser(n,s,e,p);
        else if(type == "ExecutiveUser")
            this->model->AddExecutiveUser(n,s,e,p);
        this->view->SetMessage(tr("Utente Aggiunto con successo."),Qt::green);
    }
    else
    {
        this->view->SetMessage(tr("Password non coincidenti."),Qt::red);
    }
}

void LinQedInAdminController::dbDoOperation(const QString & o,const QString& p)
{
    if(o == "Save")
    {
        bool r;
        if(p == "")
        {
            r = this->model->SaveDB();
        }
        else
        {
            r = this->model->SaveDB(p);
        }

        if(r)
            this->view->SetMessage(tr("DB salvato con successo."),Qt::green);
        else
            this->view->SetMessage(tr("E' necessario caricare un DB."),Qt::red);
    }
    else if(o == "Restart")
    {
        if(this->model->RestartDB())
            this->view->SetMessage(tr("DB ricaricato con successo."),Qt::green);
        else
            this->view->SetMessage(tr("E' necessario caricare un DB."),Qt::red);
    }
    else if( o == "Load")
    {
        bool result = this->model->LoadDB(p);
        if(result)
            this->view->SetMessage(tr("DB caricato con successo."),Qt::green);
        else
            this->view->SetMessage(tr("Errore. Assicurarsi che il DB non sia attualmente in uso o che la Path inserita sia corretta."),Qt::red);
    }
    else if(o == "Close")
    {
        if(this->model->CloseDB())
            this->view->SetMessage(tr("DB chiuso con successo."),Qt::green);
        else
            this->view->SetMessage(tr("E' necessario caricare un DB."),Qt::red);
    }
}

void LinQedInAdminController::removeUser(const QString &email)
{
    if(this->model->RemoveUser(email))
        this->view->SetMessage(tr("Utente rimosso con successo."),Qt::green);
    else
        this->view->SetMessage(tr("Errore, l'utente selezionato non esiste."),Qt::red);
}

void LinQedInAdminController::changeSubscryptionType(const QString &email, const QString &type)
{
    this->model->ChangeSubscriptionType(this->model->FindUser(email),type);
    this->view->SetMessage(tr("Tipo dell'utente modificato con successo."),Qt::green);
}


