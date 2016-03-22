Imports InterfaceVB
Imports InterfaceCS
Imports InterfaceCpp
Imports Wrapper

Module Module1

    Dim WithEvents VBtest As IInterfaceVB
    Dim WithEvents CStest As IInterfaceCS
    Dim WithEvents Cpptest As IInterfaceCpp
    Dim WithEvents Mixedtest As Managed

    Sub Main()
        Console.WriteLine("*****************************")
        If (IntPtr.Size = 4) Then
            Console.WriteLine("* 32-х битное приложение!!! *")
        ElseIf (IntPtr.Size = 8) Then
            Console.WriteLine("* 64-х битное приложение!!! *")
        End If
        Console.WriteLine("*****************************")

        NewCpp()
        VB()
        CS()
        Cpp()
        Wrapper()
        Console.ReadKey()
    End Sub

    Private Sub EventHandler(ByVal sender As Object, ByVal str As String) Handles VBtest.EventVB1, CStest.EventCS1, Cpptest.EventCpp2
        Console.WriteLine("Обработчик события поймал событие: " & Chr(13) & Chr(10) & str)
        Console.WriteLine()
    End Sub

    Private Sub EventHandler() Handles Cpptest.EventCpp1
        Console.WriteLine("Обработчик события поймал событие без параметров.")
        Console.WriteLine()
    End Sub


    Private Sub EventHandler(ByVal str As String) Handles Mixedtest.ValueChanged
        Console.WriteLine("Обработчик события поймал событие: " & Chr(13) & Chr(10) & str)
        Console.WriteLine()
    End Sub
    Private Function func(ByVal a As Integer, ByVal b As Integer) As Integer
        If ((a - b) >= 0) Then
            Return 1
        End If
        Return 0
    End Function

    Private Sub NewCpp()
        Dim sow As New ManagedObjectWrapper
        Dim Wrapper As New NativeMethods
        Dim call_ As New CompareCallback(AddressOf func)
        Dim a As Integer = sow.GetStringLength("Первая строка")
        Dim b As Integer = sow.GetStringLength("Вторая длинная строка")
        Console.WriteLine(Wrapper.Max(a, b, call_))
        sow.FloatProperty = 20.568F
        Dim ret As Single = sow.FloatProperty
        Console.WriteLine(sow.ToString())

        Console.WriteLine("           Managed wrapper for native C DLL         ")
        Dim call2 As CompareCallback = New CompareCallback(AddressOf Wrapper.func)
        a = Wrapper.GetStringLength1("Первая строка")
        b = Wrapper.GetStringLength2("Вторая длинная строка")
        Console.WriteLine("Делегат статической функции")
        Console.WriteLine(Wrapper.Max(a, b, call_))
        a = Wrapper.GetStringLength1("Первая строка еще длиннее")
        Console.WriteLine("Делегат функции-члена")
        Console.WriteLine(Wrapper.Max(a, b, call2))

    End Sub

    Private Sub VB()
        Console.WriteLine("         Visual Basic        ")
        Console.WriteLine()
        VBtest = New TestInterfaceVB
        VBtest.PropVB1 = 111
        Console.WriteLine("Свойство PropVB1 установлено в: " & VBtest.PropVB1)
        VBtest.MethodVB1(5)
        Console.WriteLine("=====================================================")
    End Sub

    Private Sub CS()
        Console.WriteLine("           Visual C#         ")
        Console.WriteLine()
        CStest = New TestInterfaceCS
        CStest.PropCS1 = 111
        Console.WriteLine("Свойство PropCS1 установлено в: " & CStest.PropCS1)
        CStest.MethodCS1(5)
        Console.WriteLine("=====================================================")
    End Sub

    Private Sub Cpp()
        Console.WriteLine("           Visual C++         ")
        Console.WriteLine()
        Cpptest = New InterfaceCpp.TestInterfaceCpp
        Cpptest.PropCpp1 = 111
        Console.WriteLine("Свойство PropCpp1 установлено в: " & Cpptest.PropCpp1)
        Cpptest.MethodCpp1(5)
        Cpptest.MethodCpp1(Nothing)
        Console.WriteLine("=====================================================")
    End Sub
    Private Sub Wrapper()
        Console.WriteLine("           Managed wrapper for native DLL         ")
        Console.WriteLine()
        Mixedtest = New Managed
        Mixedtest.PropMixedCpp1 = 111
        Console.WriteLine("Свойство PropManagedCpp1 установлено в: " & Mixedtest.PropMixedCpp1)
        Mixedtest.MethodMixedCpp1(5)
        Console.WriteLine("=====================================================")
    End Sub
End Module
