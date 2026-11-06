#ifndef ADDSEGDATADIALOG_H
#define ADDSEGDATADIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QLabel>
#include <QCheckBox>
#include <QListWidget>
#include <QGroupBox>
#include <QPushButton>

QT_BEGIN_NAMESPACE

class QLabel;

QT_END_NAMESPACE

class AddSegDataDialog : public QDialog {
  Q_OBJECT

 public:
  AddSegDataDialog(QWidget *parent=0);
  QSpinBox *entrancePairIndexSpin;
  QSpinBox *exitPairIndexSpin;
  QLineEdit *lowEnergyText;
  QLineEdit *highEnergyText;
  QLineEdit *lowAngleText;
  QLineEdit *highAngleText;
  QComboBox *dataTypeCombo;
  QCheckBox *thmCheck;
  QLineEdit *dataFileText;
  QLineEdit *dataNormText;
  QLineEdit *dataNormErrorText;
  QLabel *dataNormErrorLabel;
  QCheckBox *varyNormCheck;
  QLineEdit *phaseJValueText;
  QLineEdit *phaseLValueText;
  QLabel* phaseLValueLabel;
  QLabel* phaseJValueLabel;
  QLabel* totalCaptureLabel;
  QLineEdit *energyShiftText;
  QLabel *energyShiftLabel;
  QLineEdit *energyShiftErrorText;
  QLabel *energyShiftErrorLabel;
  QCheckBox *varyEnergyShiftCheck;

  QCheckBox *advancedModeCheck;
  QGroupBox *advancedModeBox;
  QComboBox *operationCombo;
  QListWidget *componentsList;
  QSpinBox *componentEntranceSpin;
  QSpinBox *componentExitSpin;
  QCheckBox *useFixedAngleCheck;
  QLineEdit *fixedAngleText;
  QLabel *fixedAngleLabel;
  QLabel *componentScalingLabel;
  QLineEdit *componentScalingText;
  QPushButton *addComponentButton;
  QPushButton *removeComponentButton;

  // UPOS (Unobserved Primary, Observed Secondary) widgets
  QCheckBox *uposCheck;
  QLabel *secondaryLLabel;
  QSpinBox *secondaryLSpin;
  QLabel *finalJLabel;
  QLineEdit *finalJText;
  QLabel *deltaLabel;
  QLineEdit *deltaText;

  ///Selects the data type by its underlying isDiff code (not combo
  ///position); falls back to "Angle Integrated" if the code is not offered
  ///for the current THM checkbox state.
  void setDataType(int code);

 public slots:
  void setChooseFile();
  void dataTypeChanged(int);
  void thmCheckChanged(int);
  void varyNormChanged(int);
  void advancedModeChanged(int);
  void operationTypeChanged(int);
  void useFixedAngleChanged(int);
  void addComponent();
  void removeComponent();
  void uposChanged(int);

 private:
  ///Rebuilds dataTypeCombo for the current THM checkbox state: THM
  ///(half-off-shell) measurements have no lab frame, so only "Angle
  ///Integrated" and "C.M. Angle Integrated" are offered; all other
  ///observables require an ordinary lab-frame two-body kinematics and are
  ///hidden while THM is checked.
  void populateDataTypeOptions();
  ///Retitles the energy group box to match the frame the low/high energy
  ///limits are interpreted in when the data file is filtered: c.m. for the
  ///"C.M. Angle Integrated" type, lab for every other type.
  void updateEnergyFrameLabels();
  QGroupBox *energyBox;
  QPushButton *okButton;
  QPushButton *cancelButton;
};

#endif
