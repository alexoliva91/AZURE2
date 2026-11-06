#ifndef TARGETINTTAB_H
#define TARGETINTTAB_H

#include <QWidget>
#include <QItemSelection>
#include <QTableView>
#include <QSignalMapper>
#include <QPointer>
#include <QSet>
#include "TargetIntModel.h"
#include "AddTargetIntDialog.h"

QT_BEGIN_NAMESPACE

class QPushButton;
class QLineEdit;

QT_END_NAMESPACE

class InfoDialog;
class SegmentsTab;

class TargetIntTab : public QWidget {
  Q_OBJECT

 public:
  TargetIntTab(QWidget *parent = 0);
  TargetIntModel* getTargetIntModel();
  ///Gives the tab access to the segment definitions so that the experimental
  ///effects dialog can tell which segment keys are THM segments.
  void setSegmentsTab(SegmentsTab* segmentsTab);
  bool writeFile(QTextStream& outStream);
  bool readFile(QTextStream& inStream);
  void reset();

 public slots:
  void addLine();
  void addLine(TargetIntData line);
  void editLine();
  void deleteLine();
  void updateButtons(const QItemSelection &selection);
  void showInfo(int which=0,QString title="");

 private:
  ///Segment keys (row numbers, as used in the segments list of a target
  ///effect line) that belong to a THM segment, in either the data or the
  ///test segment table.
  QSet<int> thmSegmentKeys() const;

  QPointer<SegmentsTab> segmentsTab_;
  TargetIntModel *targetIntModel;
  QTableView *targetIntView;
  QPushButton *addButton;
  QPushButton *deleteButton;
  QSignalMapper* mapper;
  QPushButton *infoButton[5];
  static const std::vector<QString> infoText;
  QPointer<InfoDialog> infoDialog[5];
};

#endif
