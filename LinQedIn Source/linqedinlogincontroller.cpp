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

#include "linqedinlogincontroller.h"

LinQedInLoginController::LinQedInLoginController():model(new LinQedInLogin()), view(new LinQedInLoginView())
{
    //inizializzo il controllore
    initController();
}

LinQedInLoginController::LinQedInLoginController(LinQedInLogin* m, LinQedInLoginView* v):model(m),view(v)
{
    //inizializzo il controllore
    initController();
}

LinQedInLoginController::~LinQedInLoginController()
{
    //elimino la view e il model
    this->view->deleteLater();
    delete this->model;
}


//-----------------------------------------
//------------METODI PROTETTI----------------
//------------------------------------------
void LinQedInLoginController::initController() const
{
    connect(view,SIGNAL(doUserLogin(QString,QString)),this,SLOT(doUserLogin(QString,QString)));
    connect(view,SIGNAL(doAdminLogin()),this,SLOT(doAdminLogin()));
}


//---------------------------------
//------------METODI----------------
//----------------------------------

void LinQedInLoginController::Show() const
{
    view->show();
}


void LinQedInLoginController::doUserLogin(const QString& email,const QString& password)
{
    //verifico se  è utente
    if(model->DoClientLogin(email,password))
    {
        this->view->SetMessage(tr("Utente"),QColor(Qt::green));

        //elimino dallo heap la parte di login
        delete this;
    }
    else
    {
        this->view->SetMessage(tr("Dati inseriti non corretti"),QColor(Qt::red));
    }
}

void LinQedInLoginController::doAdminLogin()
{
    this->view->SetMessage(tr("Login in corso..."),QColor(Qt::green));

    if(this->model->DoAdminLogin())
    {
        this->view->SetMessage(tr("Amministratore"),QColor(Qt::green));
        //elimino dallo heap la parte di login
        delete this;
    }
    else
    {
        this->view->SetMessage(tr("Errore"),QColor(Qt::red));
    }
}
