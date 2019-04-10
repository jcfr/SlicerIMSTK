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

// .NAME vtkSlicerCollisionSimulationLogic - slicer logic class for volumes manipulation
// .SECTION Description
// This class manages the logic associated with reading, saving,
// and changing propertied of the volumes


#ifndef __vtkSlicerCollisionSimulationLogic_h
#define __vtkSlicerCollisionSimulationLogic_h

// Slicer includes
#include "vtkSlicerModuleLogic.h"

// MRML includes

// STD includes
#include <cstdlib>

#include "vtkSlicerCollisionSimulationModuleLogicExport.h"


/// \ingroup Slicer_QtModules_ExtensionTemplate
class VTK_SLICER_COLLISIONSIMULATION_MODULE_LOGIC_EXPORT vtkSlicerCollisionSimulationLogic :
  public vtkSlicerModuleLogic
{
public:

  static vtkSlicerCollisionSimulationLogic *New();
  vtkTypeMacro(vtkSlicerCollisionSimulationLogic, vtkSlicerModuleLogic);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Write the node to a temporary folder and return the path
  std::string WriteNodeToTemporaryDirectory(vtkMRMLNode* node);

protected:
  vtkSlicerCollisionSimulationLogic();
  virtual ~vtkSlicerCollisionSimulationLogic();

private:

  vtkSlicerCollisionSimulationLogic(const vtkSlicerCollisionSimulationLogic&); // Not implemented
  void operator=(const vtkSlicerCollisionSimulationLogic&); // Not implemented
};

#endif
