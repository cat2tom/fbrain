/*==========================================================================
  
  © Université de Strasbourg - Centre National de la Recherche Scientifique
  
  Date: 15/01/2013
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

#ifndef BTK_GREEDY_FEATURE_SELECTION_H
#define BTK_GREEDY_FEATURE_SELECTION_H

// ITK includes
#include "itkSmartPointer.h"
#include "itkMacro.h"
#include "itkProcessObject.h"

// Local includes
#include "btkFeatureSelectionAlgorithm.h"


namespace btk
{

/**
 * @brief Genetic algorithm used for feature selection.
 * @author Julien Pontabry
 * @ingroup FeatureSelection
 */
class GreedyFeatureSelectionAlgorithm : public FeatureSelectionAlgorithm
{
    public:
        typedef GreedyFeatureSelectionAlgorithm  Self;
        typedef FeatureSelectionAlgorithm        Superclass;
        typedef itk::SmartPointer< Self >        Pointer;
        typedef itk::SmartPointer< const Self >  ConstPointer;

        itkTypeMacro(GreedyFeatureSelectionAlgorithm,FeatureSelectionAlgorithm);
        itkNewMacro(Self);

        btkGetMacro(CurrentIteration, unsigned int);

        btkGetMacro(CurrentMessage, std::string);

        /**
         * @brief Run the algorithm.
         */
        void Update();

    protected:
        /**
         * @brief Constructor.
         */
        GreedyFeatureSelectionAlgorithm();

        /**
         * @brief Print a message on output stream.
         * @param os Output stream where the message is printed.
         * @param indent Indentation.
         */
        virtual void PrintSelf(std::ostream &os, itk::Indent indent) const;

    private:
        /**
         * @brief Current iteration of the greedy iterative search.
         */
        unsigned int m_CurrentIteration;

        /**
         * @brief Current message of the current iteration.
         */
        std::string m_CurrentMessage;
};

} // namespace btk

#endif // BTK_GREEDY_FEATURE_SELECTION_H
