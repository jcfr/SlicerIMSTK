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

// CollisionSimulation Logic includes
#include "vtkSlicerCollisionSimulationLogic.h"

// MRML includes
#include <vtkMRMLNode.h>
#include <vtkMRMLScene.h>
#include <vtkMRMLModelStorageNode.h>
#include <vtkMRMLStorableNode.h>
#include <vtkMRMLStorageNode.h>

// VTK includes
#include <vtkIntArray.h>
#include <vtkNew.h>
#include <vtkObjectFactory.h>

// STD includes
#include <cassert>

//----------------------------------------------------------------------------
vtkStandardNewMacro(vtkSlicerCollisionSimulationLogic);

//----------------------------------------------------------------------------
vtkSlicerCollisionSimulationLogic::vtkSlicerCollisionSimulationLogic()
{
}

//----------------------------------------------------------------------------
vtkSlicerCollisionSimulationLogic::~vtkSlicerCollisionSimulationLogic()
{
}

//----------------------------------------------------------------------------
const char* vtkSlicerCollisionSimulationLogic::ForceGetNodeFileName(vtkMRMLNode* node)
{
  vtkMRMLStorableNode* withStorageNode = vtkMRMLStorableNode::SafeDownCast(node);
  if (!withStorageNode)
    {
    return nullptr;
    }

  vtkMRMLStorageNode* storageNode = withStorageNode->GetStorageNode();
  if (!storageNode)
    {
    withStorageNode->AddDefaultStorageNode();
    storageNode = withStorageNode->GetStorageNode();
    }

  std::string filename = storageNode->GetFileName();
  if (filename.empty())
    {
    // Save as a temp file
    filename = this->GetApplicationLogic()->GetTemporaryPath();
    filename += node->GetName();
    filename += storageNode->GetDefaultWriteFileExtension();

    storageNode->SetFileName(filename.c_str());
    if (storageNode->WriteData(withStorageNode) != 1)
      {
      std::cerr << "Error when writing node to temporary path" << std::endl;
      return nullptr;
      }
    storageNode->SetFileName(nullptr);
    }

  return filename.c_str();
}

//----------------------------------------------------------------------------
void vtkSlicerCollisionSimulationLogic::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}