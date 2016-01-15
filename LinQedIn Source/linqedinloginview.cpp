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

#include "linqedinloginview.h"

LinQedInLoginView::LinQedInLoginView()
{
    initView();
}

LinQedInLoginView::~LinQedInLoginView()
{}


//-------------------------------------------
//------------METODI PROTETTI----------------
//-------------------------------------------
void LinQedInLoginView::initView()
{
    //istanza
    loginLbl = new QLabel(this);
    messageLbl = new QLabel(this);
    emailText = new QLineEdit(this);
    passwordText = new QLineEdit(this);
    adminLoginBtn = new QPushButton(this);
    confermaBtn = new QPushButton(this);
    confirmBox= new QHBoxLayout();
    form = new QFormLayout();
    screen = new QVBoxLayout(this);


    //config loginLbl
    loginLbl->setText(tr("LinQedIn"));
    loginLbl->setFont(QFont("Arial",20,-1,false));

    //config messageLbl
    this->SetMessage(tr("Inserisci i tuoi dati per accedere."));

    //config passwordText
    passwordText->setEchoMode(QLineEdit::Password);

    //config ConfermaBtn
    confermaBtn->setMaximumWidth(100);
    confermaBtn->setText(tr("Login"));

    //config adminLoginBtn
    adminLoginBtn->setText("Accedi come amministratore");
    adminLoginBtn->setStyleSheet("border:none;");

    //config confirmBox
    confirmBox->addWidget(adminLoginBtn,0,Qt::AlignLeft);
    confirmBox->addWidget(confermaBtn,0,Qt::AlignRight);

    //config Layout Form
    form->addRow(tr("Email"),emailText);
    form->addRow(tr("Password"),passwordText);

    //config Layout Screen
    screen->addWidget(loginLbl); //aggiungo l'oggetto
    screen->setAlignment(loginLbl,Qt::AlignCenter); //imposto l'oggetto al centro
    screen->addWidget(messageLbl); // aggiungo la label per i messaggi
    screen->setAlignment(messageLbl,Qt::AlignCenter); //imposto l'oggetto al centro
    screen->addLayout(form); //aggiungo il layout form
    screen->addLayout(confirmBox);

    //config this
    this->setWindowModality(Qt::ApplicationModal); //vissualizza al centro
    this->setWindowTitle(tr("Login")); //importo il titolo
    this->setFixedWidth(700); //imposto la larghezza della schermata
    this->setFixedHeight(175); //imposto l'altezza della schermata
    this->setLayout(screen); //includo il layout screen

    //config signals
    connect(confermaBtn,SIGNAL(clicked()),this,SLOT(loginClicked()));
    connect(adminLoginBtn,SIGNAL(clicked()),this,SIGNAL(doAdminLogin()));
}

//---------------------------------
//------------METODI----------------
//----------------------------------
void LinQedInLoginView::loginClicked()
{
    emit doUserLogin(emailText->text(),passwordText->text());
}

void LinQedInLoginView::SetMessage(const QString &message, const QColor& c)
{
    QPalette pal = messageLbl->palette(); //setto un nuovo colore
    pal.setColor(QPalette::WindowText,c);
    messageLbl->setPalette(pal); //cambio palette
    messageLbl->setText(message);
}
