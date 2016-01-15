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

#include "linqedinadminview.h"

LinQedInAdminView::LinQedInAdminView()
{
    this->initView();
}

LinQedInAdminView::~LinQedInAdminView()
{}

//-------------------------------------------
//------------METODI PROTETTI----------------
//-------------------------------------------
void LinQedInAdminView::initView()
{
    //----------------------------------------------------------------
    //----------ISTANZA Label----------------------------------------
    this->adminLbl = new QLabel(this);
    this->messageLbl = new QLabel(this);


    //config adminLbl
    this->adminLbl->setText(tr("Benvenuto Amministratore"));
    this->adminLbl->setFont(QFont("Arial",20,-1,false));
    this->adminLbl->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

    //config messageLbl
    this->SetMessage(tr("Inizia ad utilizzare da subito il pannello amministratore"));
    this->messageLbl->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);


    //----------------------------------------------------------------
    //----------ISTANZA GroupBox DB-----------------------------------
    this->dbGB = new QGroupBox(this);
    this->dbOperationsCB = new QComboBox(this);
    this->dbPathText = new QLineEdit(this);
    this->dbProceedBtn = new QPushButton(this);
    this->dbOperationsLayout = new QHBoxLayout(this);

    //config dbOperationsCB
    this->dbOperationsCB->addItem(tr("Load"));
    this->dbOperationsCB->addItem(tr("Save"));
    this->dbOperationsCB->addItem(tr("Close"));
    this->dbOperationsCB->addItem(tr("Restart"));
    this->dbOperationsCB->setMaxVisibleItems(3);

    //config dbPathTexT


    //config dbProceedBtn
    this->dbProceedBtn->setText(tr("Procedi"));

    //config dbOperationsLayout
    this->dbOperationsLayout->addWidget(this->dbOperationsCB);
    this->dbOperationsLayout->addWidget(this->dbPathText);
    this->dbOperationsLayout->addWidget((this->dbProceedBtn));

    //config DBGB
    this->dbGB->setTitle(tr("Operazioni sul Database"));
    this->dbGB->setLayout(this->dbOperationsLayout);
    this->dbGB->setStyleSheet("QGroupBox{border: 1px solid gray;border-radius: 3px;margin:20px;padding-top:20px;} QGroupBox::title{left:10px;top:3px;}");
    this->dbGB->adjustSize();
    this->dbGB->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);



    //----------------------------------------------------------------
    //----------ISTANZA GroupBox User-----------------------------------
    this->addUsersGB = new QGroupBox(this);
    this->addUserNameText = new QLineEdit(this);
    this->addUserUsernameText = new QLineEdit(this);
    this->addUserEmailText = new QLineEdit(this);
    this->addUserPassowrdText = new QLineEdit(this);
    this->addUserPassowrdConfirmText = new QLineEdit(this);
    this->addUserProceedBtn = new QPushButton(this);
    this->addUserFormLayout = new QFormLayout(this);
    this->addUserTypeCB = new QComboBox(this);

    //config addUserPasswordText
    this->addUserPassowrdText->setEchoMode(QLineEdit::Password);

    //config addUserPasswordConfirmText
    this->addUserPassowrdConfirmText->setEchoMode(QLineEdit::Password);

    //config addUserTypeCB
    this->addUserTypeCB->addItem(tr("FreeUser"));
    this->addUserTypeCB->addItem(tr("BusinessUser"));
    this->addUserTypeCB->addItem(tr("ExecutiveUser"));

    //config addUserProceedBtn
    this->addUserProceedBtn->setText(tr("Procedi"));

    //config addUserFormLayout
    this->addUserFormLayout->addRow(tr("Nome"),this->addUserNameText);
    this->addUserFormLayout->addRow(tr("Cognome"),this->addUserUsernameText);
    this->addUserFormLayout->addRow(tr("Email"),this->addUserEmailText);
    this->addUserFormLayout->addRow(tr("Password"),this->addUserPassowrdText);
    this->addUserFormLayout->addRow(tr("Ripeti Password"),this->addUserPassowrdConfirmText);
    this->addUserFormLayout->addRow(tr("Iscrizione"),this->addUserTypeCB);
    this->addUserFormLayout->addWidget(this->addUserProceedBtn);
    this->addUserFormLayout->setAlignment(addUserProceedBtn,Qt::AlignRight);

    //config addUsersGB
    this->addUsersGB->setTitle(tr("Creazione Nuovo Utente"));
    this->addUsersGB->setLayout(this->addUserFormLayout);
    this->addUsersGB->setStyleSheet("QGroupBox{border: 1px solid gray;border-radius: 3px;margin:20px;padding-top:20px;} QGroupBox::title{left:10px;top:3px;}");
    this->addUsersGB->adjustSize();
    this->addUsersGB->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);


    //----------------------------------------------------------------
    //----------ISTANZA GroupBox Find-----------------------------------
    findGB = new QGroupBox(this);
    findNameText = new QLineEdit(this);
    findSurnameText = new QLineEdit(this);
    findEmailText = new QLineEdit(this);
    findProceedBtn = new QPushButton(this);
    findResultTbl = new QTableWidget(this);
    removeUserBtn = new QPushButton(this);
    changeSubTypeBtn = new QPushButton(this);
    subscriptyonTypeCB = new QComboBox(this);

    findFormLayout = new QFormLayout();
    findHVOLayout = new QHBoxLayout();
    findVUOLayout = new QVBoxLayout();
    findHLayout = new QHBoxLayout();
    findVLayout = new QVBoxLayout();


    //config findProceedBtn
    this->findProceedBtn->setText(tr("Cerca"));

    //config removeUserBtn
    this->removeUserBtn->setText(tr("Elimina Utente"));

    //config changeSubTypeBtn
    this->changeSubTypeBtn->setText(tr("Cambia Tipo Utente"));

    //config findRisultTbl
    this->findResultTbl->setColumnCount(4);
    this->findResultTbl->setHorizontalHeaderLabels(QStringList()<<"Nome"<<"Cognome"<<"Email"<<"Tipo");
    this->findResultTbl->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);


    //config subscriptyonTypeCB
    this->subscriptyonTypeCB->addItem(tr("FreeUser"));
    this->subscriptyonTypeCB->addItem(tr("BusinessUser"));
    this->subscriptyonTypeCB->addItem(tr("ExecutiveUser"));

    //config findFormLayout
    this->findFormLayout->addRow(tr("Nome"),this->findNameText);
    this->findFormLayout->addRow(tr("Cognome"),this->findSurnameText);
    this->findFormLayout->addRow(tr("Email"),this->findEmailText);
    this->findFormLayout->addWidget(this->findProceedBtn);
    this->findFormLayout->setAlignment(this->findProceedBtn,Qt::AlignRight);

    //config findHUOLayout
    this->findHVOLayout->addWidget(this->subscriptyonTypeCB);
    this->findHVOLayout->addWidget(this->changeSubTypeBtn);

    //config findVUOLayout
    this->findVUOLayout->addWidget(this->removeUserBtn);
    this->findVUOLayout->addLayout(this->findHVOLayout);
    this->findVUOLayout->insertStretch(3,100);

    //config findHLayout
    this->findHLayout->addWidget(this->findResultTbl);
    this->findHLayout->addLayout(this->findVUOLayout);

    //config FindVLayout
    this->findVLayout->addLayout(this->findFormLayout);
    this->findVLayout->addLayout(this->findHLayout);

    //config findGB
    this->findGB->setTitle(tr("Cerca Utenti"));
    this->findGB->setLayout(this->findVLayout);
    this->findGB->setStyleSheet("QGroupBox{border: 1px solid gray;border-radius: 3px;margin:20px;padding-top:20px;} QGroupBox::title{left:10px;top:3px;}");
    this->findGB->adjustSize();
    this->findGB->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);


    //config gridLayout
    this->gridLayout = new QGridLayout();
    this->gridLayout->addWidget(this->addUsersGB,2,0,Qt::AlignTop);
    this->gridLayout->addWidget(this->dbGB,2,1,Qt::AlignTop);


    //config screenLayout
    this->screenLayout = new QVBoxLayout();
    this->screenLayout->addWidget(this->adminLbl);
    this->screenLayout->setAlignment(this->adminLbl,Qt::AlignHCenter);
    this->screenLayout->addWidget(this->messageLbl);
    this->screenLayout->setAlignment(this->messageLbl,Qt::AlignHCenter);
    this->screenLayout->addWidget(this->findGB);
    this->screenLayout->addLayout(this->gridLayout);


    //config this
    this->setWindowTitle(tr("LinQedIn Admin"));
    this->setLayout(this->screenLayout);
    this->setMinimumSize(850,650);

    //connessioni
    connect(this->dbOperationsCB,SIGNAL(currentIndexChanged(QString)),this,SLOT(currentDBOChanged(const QString&)));
    connect(this->dbProceedBtn,SIGNAL(clicked()),this,SLOT(dbDoOperation()));
    connect(this->addUserProceedBtn,SIGNAL(clicked()),this,SLOT(dbAddNewUser()));
    connect(this->removeUserBtn,SIGNAL(clicked()),this,SLOT(dbRemoveUser()));
    connect(this->changeSubTypeBtn,SIGNAL(clicked()),this,SLOT(dbChangeUserSub()));
    connect(this->findProceedBtn,SIGNAL(clicked()),this,SLOT(dbFindUsers()));
}




//---------------------------------
//------------METODI----------------
//----------------------------------
void LinQedInAdminView::SetMessage(const QString &message, const QColor& c)
{
    QPalette pal = messageLbl->palette(); //setto un nuovo colore
    pal.setColor(QPalette::WindowText,c);
    messageLbl->setPalette(pal); //cambio palette
    messageLbl->setText(message);
}


//Private sloats
void LinQedInAdminView::dbFindUsers()
{
    emit this->dbFindUsers(this->findNameText->text(),this->findSurnameText->text(),this->findEmailText->text());
}

void LinQedInAdminView::currentDBOChanged(const QString &text)
{
    if(text == "Restart")
        this->dbPathText->setDisabled(true);
    else if(text == "Close")
        this->dbPathText->setDisabled(true);
    else
        this->dbPathText->setDisabled(false);
}

void LinQedInAdminView::dbDoOperation()
{
    emit this->dbDoOperation(this->dbOperationsCB->currentText(),this->dbPathText->text());
    //cancello tuttociò che è presente nella tabella
    this->findResultTbl->clearContents();
    this->findResultTbl->setRowCount(0);
}

void LinQedInAdminView::dbAddNewUser()
{
    QString name = addUserNameText->text();
    QString surname = addUserUsernameText->text();
    QString email = addUserEmailText->text();
    QString password = addUserPassowrdText->text();
    QString cPassword = addUserPassowrdConfirmText->text();
    QString type = addUserTypeCB->currentText();

    if(name!=""&&surname!=""&&email!=""&&password!=""&&cPassword!=""&&type!="")
        emit this->dbAddNewUser(name,surname,email,password,cPassword,type);
    else
        this->SetMessage(tr("Si prega di inserire tutti i dati richiesti."),QColor(Qt::red));
}

void LinQedInAdminView::dbRemoveUser()
{
    //verifico che sia selezionata una riga
    if(this->findResultTbl->currentIndex().isValid())
    {
        //ottengo il puntatore all'oggetto
        QWidget* label = this->findResultTbl->cellWidget(this->findResultTbl->currentRow(),2);
        //faccio conversione a runtime e ottengo il testo
        QString ID  = (dynamic_cast<QLabel*>(label))->text();
        //emetto il segnale
        emit this->dbRemoveUser(ID);
        //elimino dalla tabella
        this->findResultTbl->removeRow(this->findResultTbl->currentRow());
    }
    else
    {
        this->SetMessage(tr("Selezionare un utente da rimuovere."),Qt::red);
    }
}

void LinQedInAdminView::dbChangeUserSub()
{
    //verifico che sia selezionata una riga
    if(this->findResultTbl->currentIndex().isValid())
    {
        //ottengo il puntatore all'oggetto
        QWidget* label = this->findResultTbl->cellWidget(this->findResultTbl->currentRow(),2);
        //faccio conversione a runtime e ottengo il testo
        QString email  = (dynamic_cast<QLabel*>(label))->text();
        //emetto il segnale
        emit this->dbChangeUserSub(email,this->subscriptyonTypeCB->currentText());
        //modifico la voce nella tabella
        this->findResultTbl->setCellWidget(this->findResultTbl->currentRow(),3,new QLabel(this->subscriptyonTypeCB->currentText()));
    }
    else
    {
        this->SetMessage(tr("Selezionare un utente da rimuovere."),Qt::red);
    }
}

void LinQedInAdminView::ShowUsersResult(QVector<AUser*> usersList,bool l)
{
    //cancello tutto
    this->findResultTbl->clearContents();
    this->findResultTbl->setRowCount(0);

    if(l)
    {
        for(QVector<AUser*>::const_iterator it = usersList.begin();it != usersList.end();++it)
        {
            //ottengo il numero delle righe
            int nRow = this->findResultTbl->rowCount();
            //aggiungo una riga alla fine
            this->findResultTbl->insertRow(nRow);
            //setto i valori
            this->findResultTbl->setCellWidget(nRow,0,new QLabel((*it)->Profile->GetName()));
            this->findResultTbl->setCellWidget(nRow,1,new QLabel((*it)->Profile->GetSurname()));
            this->findResultTbl->setCellWidget(nRow,2,new QLabel((*it)->Profile->GetEmail()));
            this->findResultTbl->setCellWidget(nRow,3,new QLabel((*it)->GetSubscriptionType()));
        }
        this->SetMessage(QString::number(usersList.size()) + " risultati trovati con successo.",Qt::green);
    }
    else
    {
        this->SetMessage(tr("Nessun database caricato."),Qt::red);
    }
}



