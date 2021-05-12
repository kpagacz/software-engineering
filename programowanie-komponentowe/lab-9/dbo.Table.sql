CREATE TABLE [dbo].[Table]
(
	[Id] INT NOT NULL PRIMARY KEY IDENTITY, 
    [FirstName] NVARCHAR(50) NOT NULL, 
    [LastName] NVARCHAR(50) NOT NULL, 
    [DateBegin] DATE NOT NULL, 
    [Salary] DECIMAL(10, 2) NOT NULL, 
    [Manager] BIT NOT NULL
)
