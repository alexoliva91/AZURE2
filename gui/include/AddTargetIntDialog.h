#ifndef ADDTARGETINTDIALOG_H
#define ADDTARGETINTDIALOG_H

#include <QDialog>
#include <QSet>
#include <string>
#include <vector>

QT_BEGIN_NAMESPACE

class QLineEdit;
class QSpinBox;
class QDoubleSpinBox;
class QCheckBox;
class QTableWidget;
class QGroupBox;
class QSize;
class QComboBox;
class QPushButton;
class QLabel;

QT_END_NAMESPACE

class AddTargetIntDialog : public QDialog {
  Q_OBJECT

 public:
  AddTargetIntDialog(QWidget *parent=0);
  QCheckBox *isConvolutionCheck;
  QCheckBox *isConvolutionDependentCheck;
  QCheckBox *isTargetIntegrationCheck;
  QCheckBox *isQCoefficientCheck;
  QLineEdit *sigmaText;
  QLineEdit *segmentsListText;
  QSpinBox *numPointsSpin;
  QSpinBox *numParametersSpin;
  QSpinBox *numQCoefficientSpin;
  QSpinBox *numConvCoefficientSpin;
  QLineEdit *densityText;
  QLineEdit *stoppingPowerEqText;
  QComboBox *elementComboBox;
  QLineEdit *compoundText;
  QPushButton *fetchStoppingPowerButton;
  QCheckBox *isStraggling;
  QLineEdit *stragglingCoefficientText;
  QDoubleSpinBox *resonanceWidthMultiplierSpin;
  QDoubleSpinBox *pointsPerWidthSpin;
  QLineEdit *energyText;
  QLineEdit *deltaEText;
  QPushButton *calculateDeltaEButton;
  QTableWidget *parametersTable;
  QTableWidget *qCoefficientTable;
  QTableWidget *convCoefficientTable;
  QList<double> tempParameters;
  QList<double> tempQCoefficients;
  QList<double> tempConvCoefficients;
  QLineEdit *convolutionEqText;
  void createParameterItem(int row, double value = 0.0);
  void createQCoefficientItem(int row, double value = 1.0);
  void createConvCoefficientItem(int row, double value = 1.0);

  ///Declares which segment keys belong to THM (half-off-shell) segments.
  ///Whenever the segments list names one of them, every experimental effect
  ///but the Gaussian convolution is switched off and disabled: a THM
  ///measurement has no beam slowing down in a target, so target integration,
  ///straggling and attenuation coefficients are meaningless for it (the
  ///engine rejects them in EData::ReadTargetEffectsFile).
  void setTHMSegmentKeys(const QSet<int>& keys);

 public slots:
  void convolutionCheckChanged(bool checked);
  void segmentsListChanged(const QString& text);

  void targetIntCheckChanged(bool checked);
  void parameterSpinChanged(int newNumber);
  void parameterChanged(int row, int column);

  void qCoefficientCheckChanged(bool checked);
  void qCoefficientSpinChanged(int newNumber);
  void qCoefficientChanged(int row, int column);

  void convCoefficientCheckChanged(bool checked);
  void convCoefficientSpinChanged(int newNumber);
  void convCoefficientChanged(int row, int column);

  void elementSelectionChanged(int index);
  void fetchStoppingPowerParameters();
  void calculateDeltaE();

 private:
  ///Switches the non-convolution effects on or off to match the current
  ///segments list, and shows the explanatory notice while they are off.
  void updateTHMRestrictions();
  ///Expands a segments list of the form "1-3,5" into individual keys, using
  ///the same syntax as TargetEffect::GetSegmentsList().
  static QSet<int> parseSegmentsList(const QString& text);

  QSet<int> thmSegmentKeys_;
  QLabel *thmNoticeLabel;
  QPushButton *okButton;
  QPushButton *cancelButton;
  QGroupBox *stoppingPowerBox;
  QGroupBox *qCoefficientBox;
  QGroupBox *convCoefficientBox;
  
  int selectedElement_;
  void populateElementComboBox();
  void updateStoppingPowerFromElement(int element);
  void updateStoppingPowerFromCompound(const std::string& formula);
  void updateStoppingPowerGUI(const QString& equation, const std::vector<double>& parameters, const QString& materialName);
};

#endif
