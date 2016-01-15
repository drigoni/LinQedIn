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

#include "usercontactsnetview.h"

UserContactsNetView::UserContactsNetView()
{
    this->initView();
}

UserContactsNetView::~UserContactsNetView()
{}


//---------------------------------
//------------METODI PROTETTI---------------
//----------------------------------
void UserContactsNetView::initView()
{
    MessageLbl = new QLabel(this);
    VBox = new QVBoxLayout();
    FriendTable = new QTableWidget(this);
    GridBox = new QGridLayout();
    VBoxBtn = new QVBoxLayout();
    RemoveBtn = new QPushButton(this);
    RefreshBtn = new QPushButton(this);
    ViewUserProfileBtn = new QPushButton(this);

    //config FriendTable
    this->FriendTable->setColumnCount(6);
    this->FriendTable->setHorizontalHeaderLabels(QStringList()<<"Nome"<<"Cognome"<<"Email"<<"Età"<<"Sesso"<<"Stato");
    this->FriendTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //config RemoveBtn
    this->RemoveBtn->setText(tr("Rimuovi amico"));

    //config RefreshBtn
    this->RefreshBtn->setText(tr("Aggiorna"));

    //config viewProfileBtn
    ViewUserProfileBtn->setText(tr("Vedi profilo"));

    //config VBoxBtn
    this->VBoxBtn->addWidget(RefreshBtn,0,Qt::AlignTop);
    this->VBoxBtn->addWidget(ViewUserProfileBtn,0,Qt::AlignTop);
    this->VBoxBtn->addWidget(RemoveBtn,0,Qt::AlignTop);
    this->VBoxBtn->insertSpacing(2,500);


    //config GridBox
    this->GridBox->addWidget(FriendTable,0,0);
    this->GridBox->addLayout(VBoxBtn,0,1);

    //config VBox
    this->VBox->addWidget(this->MessageLbl,0,Qt::AlignCenter);
    this->VBox->addLayout(this->GridBox);

    //config Widget
    this->setLayout(this->VBox);

    //connect
    connect(this->RemoveBtn,SIGNAL(clicked()),this,SLOT(RemoveClick()));
    connect(this->RefreshBtn,SIGNAL(clicked()),this,SIGNAL(FriendsNetworkAsked()));
    connect(this->ViewUserProfileBtn,SIGNAL(clicked()),this,SLOT(ViewProfileClicked()));
}


//---------------------------------
//------------METODI----------------
//----------------------------------
void UserContactsNetView::SetMessage(const QString &message, const QColor& c)
{
    QPalette pal = MessageLbl->palette(); //setto un nuovo colore
    pal.setColor(QPalette::WindowText,c);
    MessageLbl->setPalette(pal); //cambio palette
    MessageLbl->setText(message);
}

void UserContactsNetView::ShowAllFriendsNetwork(const QList<const UserBaseInformations*> p)
{
    //cancello tutto
    this->FriendTable->clearContents();
    this->FriendTable->setRowCount(0);

    //Per ogni utente della lista inserisco i dati nella tabella
    for(QList<const UserBaseInformations*>::const_iterator i = p.begin();i!=p.end();++i)
    {
        //ottengo il numero delle righe
        int nRow = this->FriendTable->rowCount();
        //aggiungo una riga alla fine
        this->FriendTable->insertRow(nRow);
        //setto i valori
        this->FriendTable->setCellWidget(nRow,0,new QLabel((*i)->GetName()));
        this->FriendTable->setCellWidget(nRow,1,new QLabel((*i)->GetSurname()));
        this->FriendTable->setCellWidget(nRow,2,new QLabel((*i)->GetEmail()));
        this->FriendTable->setCellWidget(nRow,3,new QLabel(QString::number((*i)->GetAge())));
        if((*i)->GetGender() == 0)
            this->FriendTable->setCellWidget(nRow,4,new QLabel(tr("Non Segnalato")));
        else if((*i)->GetGender() == 1)
            this->FriendTable->setCellWidget(nRow,4,new QLabel(tr("Maschio")));
        else
            this->FriendTable->setCellWidget(nRow,4,new QLabel(tr("Femmina")));
        this->FriendTable->setCellWidget(nRow,5,new QLabel((*i)->GetCountry()));

    }
    //setto il messaggio
    this->SetMessage(tr("Amici: ") + QString::number(p.size()));
}

void UserContactsNetView::RemoveClick()
{
    //verifico che sia selezionata una riga
    if(this->FriendTable->currentIndex().isValid())
    {
        //ottengo il puntatore all'oggetto
        QWidget* label = this->FriendTable->cellWidget(this->FriendTable->currentRow(),2);
        //faccio conversione a runtime e ottengo il testo
        QString email  = (dynamic_cast<QLabel*>(label))->text();
        //emetto il segnale
        emit this->RemoveFriendClicked(email);
        //elimino dalla tabella
        this->FriendTable->removeRow(this->FriendTable->currentRow());

        //setto il messaggio
        this->SetMessage(tr("Utente rimosso dagli amici."),Qt::green);
    }
    else
    {
        //setto il messaggio
        this->SetMessage(tr("Selezionare un amico da rimuovere."),Qt::red);
    }
}

void UserContactsNetView::ViewProfileClicked()
{
    //verifico che sia selezionata una riga
    if(this->FriendTable->currentIndex().isValid())
    {
        //ottengo il puntatore all'oggetto
        QWidget* label = this->FriendTable->cellWidget(this->FriendTable->currentRow(),2);
        //faccio conversione a runtime e ottengo il testo
        QString email  = (dynamic_cast<QLabel*>(label))->text();
        //emetto il segnale
        emit this->ViewProfile(email);
    }
    else
    {
        //setto il messaggio
        this->SetMessage(tr("Selezionare un utente."),Qt::red);
    }
}

