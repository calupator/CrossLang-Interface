
Public Interface IInterfaceVB
    Property PropVB1() As Integer
    Sub MethodVB1(ByVal X As Integer)
    Event EventVB1(ByVal sender As Object, ByVal str As String)

End Interface

Public Class TestInterfaceVB
    Implements IInterfaceVB

    ' Holds the value of the property.
    Private pval As Integer

    Public Event EventVB1(ByVal sender As Object, ByVal str As String) Implements IInterfaceVB.EventVB1

    Public Sub MethodVB1(ByVal X As Integer) Implements IInterfaceVB.MethodVB1
        Console.WriteLine("Метод MethodVB1 получил параметр: " & X)
        RaiseEvent EventVB1(Me, vbTab & "Аргумент метода MethodVB1: " & X)
    End Sub

    Public Property PropVB1() As Integer Implements IInterfaceVB.PropVB1
        Get
            Return pval
        End Get
        Set(ByVal value As Integer)
            pval = value
        End Set
    End Property
End Class