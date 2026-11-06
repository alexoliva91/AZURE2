#ifndef ADDSEGTESTDIALOG_H
#define ADDSEGTESTDIALOG_H

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

class AddSegTestDialog : public QDialog {
  Q_OBJECT

 public:
  AddSegTestDialog(QWidget *parent=0);
  QSpinBox *entrancePairIndexSpin;
  QSpinBox *exitPairIndexSpin;
  QLineEdit *lowEnergyText;
  QLineEdit *highEnergyText;
  QLineEdit *energyStepText;
  QLineEdit *lowAngleText;
  QLineEdit *highAngleText;
  QLineEdit *angleStepText;
  QComboBox *dataTypeCombo;
  QCheckBox *thmCheck;
  QLineEdit *phaseJValueText;
  QLineEdit *phaseLValueText;
  QLabel *phaseJValueLabel;
  QLabel *phaseLValueLabel;
  QLabel *angDistLabel;
  QLabel *totalCaptureLabel;
  QSpinBox *angDistSpin;

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

  ///Selects the data type by its underlying isDiff code (not combo
  ///position); falls back to "Angle Integrated" if the code is not offered
  ///for the current THM checkbox state.
  void setDataType(int code);

 public slots:
  void dataTypeChanged(int);
  void thmCheckChanged(int);
  void advancedModeChanged(int);
  void operationTypeChanged(int);
  void useFixedAngleChanged(int);
  void addComponent();
  void removeComponent();

 private:
  ///Rebuilds dataTypeCombo for the current THM checkbox state: THM
  ///(half-off-shell) measurements have no lab frame, so only "Angle
  ///Integrated" and "C.M. Angle Integrated" are offered; all other
  ///observables require an ordinary lab-frame two-body kinematics and are
  ///hidden while THM is checked.
  void populateDataTypeOptions();
  ///Retitles the energy group box to match the frame the low/high energy
  ///grid limits are interpreted in: c.m. for the "C.M. Angle Integrated"
  ///type, lab for every other type.
  void updateEnergyFrameLabels();
  QGroupBox *energyBox;
  QPushButton *okButton;
  QPushButton *cancelButton;
};

#endif
