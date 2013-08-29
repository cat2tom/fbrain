PROJECT(Experimental)
INCLUDE_REGULAR_EXPRESSION("^.*$")

INCLUDE_DIRECTORIES(
    ${ANN_INCLUDE_DIR}
    ${TCLAP_DIRECTORY}
    ${Code_SOURCE_DIR}/Denoising
    ${Code_SOURCE_DIR}/Reconstruction
    ${Code_SOURCE_DIR}/Reconstruction/SuperResolution
    ${Code_SOURCE_DIR}/Diffusion
    ${Code_SOURCE_DIR}/Segmentation
    ${Code_SOURCE_DIR}/Transformations
    ${Code_SOURCE_DIR}/Registration
    ${Code_SOURCE_DIR}/Maths
    ${Code_SOURCE_DIR}/Visualization
    ${Code_SOURCE_DIR}/ImageFilters
    ${Code_SOURCE_DIR}/Tools


)

ADD_EXECUTABLE(btkIntersectionRegistration btkIntersectionRegistration.cxx
${fbrain_SOURCE_DIR}/Code/Tools/btkImageHelper.h
${fbrain_SOURCE_DIR}/Code/Registration/btkSlicesIntersectionVNLCostFunction.hxx
${fbrain_SOURCE_DIR}/Code/Registration/btkSlicesIntersectionITKCostFunction.hxx
${fbrain_SOURCE_DIR}/Code/Reconstruction/btkLowToHighResolutionFilter.hxx
${fbrain_SOURCE_DIR}/Code/Registration/btkOptimizer.cxx ${fbrain_SOURCE_DIR}/Code/Registration/btkOptimizer.h
${fbrain_SOURCE_DIR}/Code/Registration/btkSimulatedAnnealingOptimizer.cxx ${fbrain_SOURCE_DIR}/Code/Registration/btkSimulatedAnnealingOptimizer.h
${fbrain_SOURCE_DIR}/Code/Registration/btkSmartStepGradientDescentOptimizer.cxx ${fbrain_SOURCE_DIR}/Code/Registration/btkSmartStepGradientDescentOptimizer.h
${fbrain_SOURCE_DIR}/Code/Reconstruction/btkSRHMatrixComputation.hxx
${fbrain_SOURCE_DIR}/Code/Maths/btkPSF.h
${fbrain_SOURCE_DIR}/Code/Maths/btkPSF.cxx
${fbrain_SOURCE_DIR}/Code/Maths/btkGaussianPSF.h
${fbrain_SOURCE_DIR}/Code/Maths/btkGaussianPSF.cxx
${fbrain_SOURCE_DIR}/Code/Maths/btkBoxCarPSF.h
${fbrain_SOURCE_DIR}/Code/Maths/btkBoxCarPSF.cxx
)
TARGET_LINK_LIBRARIES(btkIntersectionRegistration btkToolsLibrary btkMathsLibrary ${ITK_LIBRARIES} vtkHybrid)

ADD_EXECUTABLE(btkFSLToITKTransform btkFSLToITKTransform.cxx)
TARGET_LINK_LIBRARIES(btkFSLToITKTransform ${ITK_LIBRARIES})

INSTALL(TARGETS btkIntersectionRegistration
        btkFSLToITKTransform
        DESTINATION bin)

# ---- Dwi registrtion correction -----------------------------------------------------------------------

ADD_EXECUTABLE(btkDwiReconstruction btkDwiReconstruction.cxx
${Code_SOURCE_DIR}/Reconstruction/btkDwiReconstructionFilter.h
${Code_SOURCE_DIR}/Reconstruction/btkDwiReconstructionFilter.cxx)

TARGET_LINK_LIBRARIES(btkDwiReconstruction btkToolsLibrary btkDiffusionLibrary ${ITK_LIBRARIES})


INSTALL(TARGETS
    btkDwiReconstruction
DESTINATION bin)

