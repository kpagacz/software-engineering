CREATE TABLE [dbo].[Reprimands] (
    [WorkerId]      INT            NOT NULL,
    [Id]            INT            IDENTITY (1, 1) NOT NULL,
    [Date]          DATE           NOT NULL,
    [Description]   NVARCHAR (MAX) NULL,
    [PenaltyPoints] INT            NOT NULL,
    PRIMARY KEY CLUSTERED ([Id] ASC),
	foreign key (WorkerId) references [Workers](Id)
);

