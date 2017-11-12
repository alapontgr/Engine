Shaders/src/dummy.frag
// Module Version 10000
// Generated by (magic number): 80001
// Id's are bound by 21

                              Capability Shader
               1:             ExtInstImport  "GLSL.std.450"
                              MemoryModel Logical GLSL450
                              EntryPoint Fragment 4  "main" 9 11
                              ExecutionMode 4 OriginUpperLeft
                              Source GLSL 450
                              Name 4  "main"
                              Name 9  "o_Color"
                              Name 11  "v_Color"
                              Name 18  "UniformBufferObject"
                              MemberName 18(UniformBufferObject) 0  "View"
                              MemberName 18(UniformBufferObject) 1  "Projection"
                              MemberName 18(UniformBufferObject) 2  "ViewProjection"
                              MemberName 18(UniformBufferObject) 3  "colour"
                              Name 20  "FDSceneParams"
                              Decorate 9(o_Color) Location 0
                              Decorate 11(v_Color) Location 0
                              MemberDecorate 18(UniformBufferObject) 0 ColMajor
                              MemberDecorate 18(UniformBufferObject) 0 Offset 0
                              MemberDecorate 18(UniformBufferObject) 0 MatrixStride 16
                              MemberDecorate 18(UniformBufferObject) 1 ColMajor
                              MemberDecorate 18(UniformBufferObject) 1 Offset 64
                              MemberDecorate 18(UniformBufferObject) 1 MatrixStride 16
                              MemberDecorate 18(UniformBufferObject) 2 ColMajor
                              MemberDecorate 18(UniformBufferObject) 2 Offset 128
                              MemberDecorate 18(UniformBufferObject) 2 MatrixStride 16
                              MemberDecorate 18(UniformBufferObject) 3 Offset 192
                              Decorate 18(UniformBufferObject) Block
                              Decorate 20(FDSceneParams) DescriptorSet 0
                              Decorate 20(FDSceneParams) Binding 0
               2:             TypeVoid
               3:             TypeFunction 2
               6:             TypeFloat 32
               7:             TypeVector 6(float) 4
               8:             TypePointer Output 7(fvec4)
      9(o_Color):      8(ptr) Variable Output
              10:             TypePointer Input 7(fvec4)
     11(v_Color):     10(ptr) Variable Input
              13:    6(float) Constant 1056964608
              14:    6(float) Constant 1065353216
              15:    7(fvec4) ConstantComposite 13 13 13 14
              17:             TypeMatrix 7(fvec4) 4
18(UniformBufferObject):             TypeStruct 17 17 17 7(fvec4)
              19:             TypePointer Uniform 18(UniformBufferObject)
20(FDSceneParams):     19(ptr) Variable Uniform
         4(main):           2 Function None 3
               5:             Label
              12:    7(fvec4) Load 11(v_Color)
              16:    7(fvec4) FAdd 12 15
                              Store 9(o_Color) 16
                              Return
                              FunctionEnd
