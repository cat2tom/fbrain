/*==========================================================================
  
  © Université de Strasbourg - Centre National de la Recherche Scientifique
  
  Date: 03/01/2013
  Author(s): Julien Pontabry (pontabry@unistra.fr)
  
  This software is governed by the CeCILL-B license under French law and
  abiding by the rules of distribution of free software.  You can  use,
  modify and/ or redistribute the software under the terms of the CeCILL-B
  license as circulated by CEA, CNRS and INRIA at the following URL
  "http://www.cecill.info".
  
  As a counterpart to the access to the source code and  rights to copy,
  modify and redistribute granted by the license, users are provided only
  with a limited warranty  and the software's author,  the holder of the
  economic rights,  and the successive licensors  have only  limited
  liability.
  
  In this respect, the user's attention is drawn to the risks associated
  with loading,  using,  modifying and/or developing or reproducing the
  software by the user in light of its specific status of free software,
  that may mean  that it is complicated to manipulate,  and  that  also
  therefore means  that it is reserved for developers  and  experienced
  professionals having in-depth computer knowledge. Users are therefore
  encouraged to load and test the software's suitability as regards their
  requirements in conditions enabling the security of their systems and/or
  data to be ensured and,  more generally, to use and operate it in the
  same conditions as regards security.
  
  The fact that you are presently reading this means that you have had
  knowledge of the CeCILL-B license and that you accept its terms.
  
==========================================================================*/

#ifndef BTKPOLYDATACOLORLINESBYORIENTATION_H
#define BTKPOLYDATACOLORLINESBYORIENTATION_H

// VTK includes
#include "vtkPolyDataAlgorithm.h"

namespace btk
{

/**
 * @class PolyDataColorLinesByOrientation
 * @brief Color the polydata lines by their mean orientation.
 * @author Julien Pontabry
 * @ingroup Tractography
 */
class PolyDataColorLinesByOrientation : public vtkPolyDataAlgorithm
{
    public:
        /**
         * @brief Create a new instance of the object.
         * @return A new instance of the object.
         */
        static PolyDataColorLinesByOrientation *New();

        vtkTypeRevisionMacro(PolyDataColorLinesByOrientation,vtkPolyDataAlgorithm);

        /**
         * @brief Display informations about the filter.
         * @param os Stream where the information is piped
         * @param indent Indentation type
         */
        void PrintSelf(ostream &os, vtkIndent indent);

    protected:
        /**
         * @brief Default constructor.
         */
        PolyDataColorLinesByOrientation();

        /**
         * @brief Default destructor.
         */
        ~PolyDataColorLinesByOrientation();

        /**
         * @brief Processing part of the filter.
         * @param request Informations
         * @param inputVector Input data
         * @param outputVector Output data
         * @return Integer for success or failure
         */
        virtual int RequestData(vtkInformation *request, vtkInformationVector **inputVector, vtkInformationVector *outputVector);

        /**
         * @brief Initialize the filter.
         * @param port Port
         * @param info Informations
         * @return Integer for success or failure
         */
        virtual int FillInputPortInformation(int port, vtkInformation *info);

    private:
        PolyDataColorLinesByOrientation(const PolyDataColorLinesByOrientation&); // purposely not implemented
        void operator=(const PolyDataColorLinesByOrientation&); // purposely not implemented
};

} // namespace btk

#endif // BTKPOLYDATACOLORLINESBYORIENTATION_H
