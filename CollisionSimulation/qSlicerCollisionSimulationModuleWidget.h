/*==============================================================================

  Program: 3D Slicer

  Portions (c) Copyright Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

==============================================================================*/

#ifndef __qSlicerCollisionSimulationModuleWidget_h
#define __qSlicerCollisionSimulationModuleWidget_h

// SlicerQt includes
#include "qSlicerAbstractModuleWidget.h"

#include "qSlicerCollisionSimulationModuleExport.h"

class qSlicerCollisionSimulationModuleWidgetPrivate;
class vtkSlicerCollisionSimulationLogic;

class vtkMRMLModelNode;
class vtkMRMLNode;

/// \ingroup Slicer_QtModules_ExtensionTemplate
class Q_SLICER_QTMODULES_COLLISIONSIMULATION_EXPORT qSlicerCollisionSimulationModuleWidget :
  public qSlicerAbstractModuleWidget
{
  Q_OBJECT
  Q_PROPERTY(int simulationStatus READ simulationStatus)
public:

  typedef qSlicerAbstractModuleWidget Superclass;
  qSlicerCollisionSimulationModuleWidget(QWidget *parent=0);
  virtual ~qSlicerCollisionSimulationModuleWidget();

  vtkSlicerCollisionSimulationLogic* simulationLogic();

  // Return the simulation status
  // This maps to imstk::SimulationStatus. Int is used to keep this accessible
  // to python
  int simulationStatus();

public slots:
  virtual void setMRMLScene(vtkMRMLScene* scene);

  // Set the current input mesh node
  void setInputMeshNode(vtkMRMLNode* node);
  void setInputMeshNode(vtkMRMLModelNode* node);

  // Set the current floor mesh node
  void setFloorMeshNode(vtkMRMLNode* node);
  void setFloorMeshNode(vtkMRMLModelNode* node);

  // Set the current floor mesh node
  void setOutputMeshNode(vtkMRMLNode* node);
  void setOutputMeshNode(vtkMRMLModelNode* node);

  // Simulation controls
  void startSimulation();
  void pauseSimulation();
  void endSimulation();

protected:
  QScopedPointer<qSlicerCollisionSimulationModuleWidgetPrivate> d_ptr;

  virtual void setup();
  void updateWidgetFromMRML();

protected slots:
  void updateFromSimulation();

private:
  Q_DECLARE_PRIVATE(qSlicerCollisionSimulationModuleWidget);
  Q_DISABLE_COPY(qSlicerCollisionSimulationModuleWidget);
};

#endif
