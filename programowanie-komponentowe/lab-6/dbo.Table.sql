CREATE TABLE [dbo].[Table]
(
	[Id] INT NOT NULL PRIMARY KEY IDENTITY, 
    [name] NVARCHAR(50) NOT NULL, 
    [surname] NVARCHAR(50) NOT NULL, 
    [birth_date] DATE NOT NULL, 
    [height] INT NOT NULL
)
