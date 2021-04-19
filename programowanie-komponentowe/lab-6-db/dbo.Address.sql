CREATE TABLE [dbo].[Address]
(
	[Id] INT NOT NULL PRIMARY KEY IDENTITY, 
    [street] NVARCHAR(10) NULL, 
    [number] NCHAR(10) NULL, 
    [people_id] INT NULL
)
