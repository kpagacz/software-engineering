CREATE TABLE [dbo].[Workers] (
    [Id]        INT             IDENTITY (1, 1) NOT NULL,
    [FirstName] NVARCHAR (100)  NOT NULL,
    [LastName]  NVARCHAR (100)  NOT NULL,
    [DateBegin] DATE            NOT NULL,
    [Salary]    DECIMAL (10, 2) NOT NULL,
    [Manager]   BIT             NOT NULL,
    PRIMARY KEY CLUSTERED ([Id] ASC)
);

