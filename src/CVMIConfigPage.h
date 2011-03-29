/****************************************************************************
** Copyright (C) 2010 CERN 
** All rights reserved.
** Contact: CernVM project (cernvm-talk@cern.ch)
** Author: Artem Harutyunyan (Artem.Harutyunyan@cern.ch)
****************************************************************************/

#ifndef CVMICONFIGPAGE_H
#define CVMICONFIGPAGE_H

#include <QWidget>
#include <QtGui>
#include <QNetworkProxy>
#include "CVMIConfig.h"

class CVMIConfigPage : public QWidget
{
  Q_OBJECT

signals:
  void displayOptionChanged();
  void configChanged();  
  void setProxy(QNetworkProxy proxy);

public:
  CVMIConfigPage(QWidget* parent = 0);

private slots:
  void changeImageDir();
  void changeVMDir();
  void changeHypervisorDir();
  void changeShowDevReleases(bool);
  void resetConfig();
  void useProxyCheckToggled(bool);
  void proxyAuthorizationCheckToggled(bool);
  void applyProxyButtonClicked();
 
private:
  QLineEdit* imageDirEdit;
  QLineEdit* vmDirEdit;   
  QLineEdit* hypervisorDirEdit;
  QCheckBox* showDevCheckBox;   
  CVMIConfig conf;

  QCheckBox *useProxyCheck;
  QGroupBox *useProxyBox;
  QVBoxLayout *useProxyLayout;
  QGridLayout *proxyDetailsLayout;
  QLabel *proxyAddressLabel;
  QLineEdit *proxyAddressInput;
  QLabel *proxyPortLabel;
  QLineEdit *proxyPortInput;
  QCheckBox *proxyAuthorizationCheck;
  QGroupBox *proxyAuthorizationBox;
  QGridLayout *proxyAuthorizationLayout;
  QLabel *proxyUsernameLabel;
  QLineEdit *proxyUsernameInput;
  QLabel *proxyPasswordLabel;
  QLineEdit *proxyPasswordInput;
  QPushButton *applyProxyButton;
};

#endif // CVMICONFIGPAGE_H

