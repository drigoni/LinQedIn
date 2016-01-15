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

#include "userssearchview.h"

UsersSearchView::UsersSearchView()
{
    initView();
}


//---------------------------------
//------------METODI PROTETTI----------------
//----------------------------------
void UsersSearchView::initView()
{
    MessageLbl=new QLabel(this);
    VBox = new QVBoxLayout();
    Form=new QFormLayout();
    ResultTable = new QTableWidget(this);
    SearchBtn=new QPushButton(this);
    nameText=new QLineEdit(this);
    surnameText=new QLineEdit(this);
    emailText=new QLineEdit(this);
    ageText=new QLineEdit(this);
    genderCB = new QComboBox(this);
    countryText=new QLineEdit(this);
    cityText=new QLineEdit(this);
    streetText=new QLineEdit(this);
    addFriend = new QPushButton(this);
    gridLayout = new QGridLayout();
    viewProfileBtn = new QPushButton(this);
    VBoxBtn = new QVBoxLayout();

    //config genderCB
    this->genderCB->addItem(tr("Non selezionato"),0);
    this->genderCB->addItem(tr("Maschio"),1);
    this->genderCB->addItem(tr("Femmina"),2);

    //config SearchBtn
    this->SearchBtn->setText("Cerca");

    //config Form
    Form->addRow(tr("Nome"),nameText);
    Form->addRow(tr("Cognome"),surnameText);
    Form->addRow(tr("Email"),emailText);
    Form->addRow(tr("Età"),ageText);
    Form->addRow(tr("Sesso"),genderCB);
    Form->addRow(tr("Stato"),countryText);
    Form->addRow(tr("Città"),cityText);
    Form->addRow(tr("Via"),streetText);
    Form->addWidget(SearchBtn);
    Form->setAlignment(SearchBtn,Qt::AlignRight);

    //config ResultTable
    ResultTable->setColumnCount(8);
    ResultTable->setHorizontalHeaderLabels(QStringList()<<"Nome"<<"Cognome"<<"Email"<<"Età"<<"Sesso"<<"Stato"<<"Città"<<"Via");
    ResultTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //config addFriend
    addFriend->setText(tr("Aggiungi agli amici"));

    //config viewProfileBtn
    viewProfileBtn->setText(tr("Vedi profilo"));

    //config VBoxBtn
    VBoxBtn->addWidget(addFriend,0,Qt::AlignTop);
    VBoxBtn->addWidget(viewProfileBtn,0,Qt::AlignTop);

    //config gridLayout
    gridLayout->addWidget(ResultTable,0,0);
    gridLayout->addLayout(VBoxBtn,0,1);

    //config VBox
    VBox->addWidget(MessageLbl,0,Qt::AlignCenter);
    VBox->addLayout(Form);
    VBox->addLayout(gridLayout);

    //config this
    this->setLayout(VBox);

    //CONNECT
    connect(SearchBtn,SIGNAL(clicked()),this,SLOT(SearchBtnClicked()));
    connect(addFriend,SIGNAL(clicked()),this,SLOT(AddFriendClicked()));
    connect(viewProfileBtn,SIGNAL(clicked()),this,SLOT(ViewProfileClicked()));
}



//---------------------------------
//------------METODI----------------
//----------------------------------
void UsersSearchView::SetMessage(const QString &message, const QColor& c)
{
    QPalette pal = MessageLbl->palette(); //setto un nuovo colore
    pal.setColor(QPalette::WindowText,c);
    MessageLbl->setPalette(pal); //cambio palette
    MessageLbl->setText(message);
}

void UsersSearchView::SetUserForm(const QString& l)
{
    if(l=="FreeUser")
    {
        //disabilito l'inserimento dati in alcuni TextBox
        surnameText->setEnabled(false);
        ageText->setEnabled(false);
        genderCB->setEnabled(false);
        countryText->setEnabled(false);
        cityText->setEnabled(false);
        streetText->setEnabled(false);
    }
    else if( l== "BusinessUser")
    {
        //disabilito l'inserimento dati in alcuni TextBox
        countryText->setEnabled(false);
        cityText->setEnabled(false);
        streetText->setEnabled(false);
    }
    else if( l == "ExecutiveUser")
    {
        //non faccio nulla
    }
}

void UsersSearchView::ShowSearchResult(const QList<const UserBaseInformations *> & l)
{
    //cancello tutto
    this->ResultTable->clearContents();
    this->ResultTable->setRowCount(0);

    //Per ogni utente della lista inserisco i dati nella tabella
    for(QList<const UserBaseInformations*>::const_iterator i = l.begin();i!=l.end();++i)
    {
        //ottengo il numero delle righe
        int nRow = this->ResultTable->rowCount();
        //aggiungo una riga alla fine
        this->ResultTable->insertRow(nRow);
        //setto i valori
        this->ResultTable->setCellWidget(nRow,0,new QLabel((*i)->GetName()));
        this->ResultTable->setCellWidget(nRow,1,new QLabel((*i)->GetSurname()));
        this->ResultTable->setCellWidget(nRow,2,new QLabel((*i)->GetEmail()));
        this->ResultTable->setCellWidget(nRow,3,new QLabel(QString::number((*i)->GetAge())));
        if((*i)->GetGender() == 0)
            this->ResultTable->setCellWidget(nRow,4,new QLabel(tr("Non Segnalato")));
        else if((*i)->GetGender() == 1)
            this->ResultTable->setCellWidget(nRow,4,new QLabel(tr("Maschio")));
        else
            this->ResultTable->setCellWidget(nRow,4,new QLabel(tr("Femmina")));
        this->ResultTable->setCellWidget(nRow,5,new QLabel((*i)->GetCountry()));
        this->ResultTable->setCellWidget(nRow,6,new QLabel((*i)->GetCity()));
        this->ResultTable->setCellWidget(nRow,7,new QLabel((*i)->GetStreet()));

    }
    //setto il messaggio
    this->SetMessage(tr("Risultati: ") + QString::number(l.size()));
}

//slot
void UsersSearchView::SearchBtnClicked()
{
    //verifico lo stato del genderCB
    UserBaseInformations* inf = new UserBaseInformations(
                nameText->text(),
                surnameText->text(),
                emailText->text(),
                (ageText->text()).toInt(),
                static_cast<UserBaseInformations::GenderType>(genderCB->currentIndex()),
                countryText->text(),
                cityText->text(),
                streetText->text());

    emit this->Search(inf);
}

void UsersSearchView::AddFriendClicked()
{
    //verifico che sia selezionata una riga
    if(this->ResultTable->currentIndex().isValid())
    {
        //ottengo il puntatore all'oggetto
        QWidget* label = this->ResultTable->cellWidget(this->ResultTable->currentRow(),2);
        //faccio conversione a runtime e ottengo il testo
        QString email  = (dynamic_cast<QLabel*>(label))->text();
        //emetto il segnale
        emit this->AddFriend(email);

        //setto il messaggio
        this->SetMessage(tr("Utente aggiunto ai propri amici."),Qt::green);
    }
    else
    {
        //setto il messaggio
        this->SetMessage(tr("Selezionare un amico da aggiungere."),Qt::red);
    }
}

void UsersSearchView::ViewProfileClicked()
{
    //verifico che sia selezionata una riga
    if(this->ResultTable->currentIndex().isValid())
    {
        //ottengo il puntatore all'oggetto
        QWidget* label = this->ResultTable->cellWidget(this->ResultTable->currentRow(),2);
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
